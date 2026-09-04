#include "waveformwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QtMath>

WaveformWidget::WaveformWidget(const QString &title, const QColor &color,
                               double minimum, double maximum, QWidget *parent)
    : QWidget(parent), m_title(title), m_color(color),
      m_minimum(minimum), m_maximum(maximum)
{
    setMinimumHeight(130);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setAttribute(Qt::WA_OpaquePaintEvent);
}

void WaveformWidget::ensureBuffer()
{
    const int count = qMax(10, width() - 2);
    if (m_samples.size() == count)
        return;
    m_samples.fill(0.0, count);
    m_valid.fill(false, count);
    m_cursor = 0;
}

void WaveformWidget::appendSample(double value)
{
    ensureBuffer();
    if (m_samples.isEmpty())
        return;

    value = qBound(m_minimum, value, m_maximum);
    m_samples[m_cursor] = value;
    m_valid[m_cursor] = true;

    // 在扫描游标前留出擦除缝，回绕后旧数据不会与新数据相连。
    const int gap = qMax(8, width() / 90);
    for (int i = 1; i <= gap; ++i)
        m_valid[(m_cursor + i) % m_valid.size()] = false;

    m_cursor = (m_cursor + 1) % m_samples.size();
    update();
}

void WaveformWidget::appendSamples(const QVector<double> &values)
{
    for (double value : values)
        appendSample(value);
}

void WaveformWidget::clearWaveform()
{
    ensureBuffer();
    m_valid.fill(false);
    m_cursor = 0;
    update();
}

void WaveformWidget::setLeadStatus(const QString &text, bool ok)
{
    m_status = text;
    m_statusOk = ok;
    update();
}

void WaveformWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    ensureBuffer();
}

void WaveformWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    ensureBuffer();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(rect(), QColor(5, 13, 18));

    painter.setPen(QPen(QColor(24, 48, 51), 1));
    for (int x = 0; x < width(); x += 25)
        painter.drawLine(x, 0, x, height());
    for (int y = 0; y < height(); y += 25)
        painter.drawLine(0, y, width(), y);

    painter.setPen(QPen(QColor(37, 70, 72), 1));
    for (int x = 0; x < width(); x += 125)
        painter.drawLine(x, 0, x, height());
    for (int y = 0; y < height(); y += 125)
        painter.drawLine(0, y, width(), y);

    painter.setFont(QFont(font().family(), 10, QFont::Bold));
    painter.setPen(m_color);
    painter.drawText(10, 20, m_title);
    painter.setFont(QFont(font().family(), 8));
    painter.setPen(m_statusOk ? QColor(108, 224, 146) : QColor(255, 92, 92));
    painter.drawText(width() - 90, 20, m_status);

    if (m_samples.size() < 2)
        return;

    const int top = 25;
    const int bottom = height() - 8;
    auto mapY = [&](double value) {
        const double normalized = (value - m_minimum) / (m_maximum - m_minimum);
        return bottom - normalized * (bottom - top);
    };

    painter.setClipRect(0, top, width(), bottom - top + 1);
    painter.setPen(QPen(m_color, 2.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    for (int x = 1; x < m_samples.size(); ++x) {
        if (!m_valid[x - 1] || !m_valid[x])
            continue;
        painter.drawLine(QPointF(x - 1, mapY(m_samples[x - 1])),
                         QPointF(x, mapY(m_samples[x])));
    }

    painter.setPen(QPen(m_color.lighter(160), 1));
    painter.drawLine(m_cursor, top, m_cursor, bottom);
}
