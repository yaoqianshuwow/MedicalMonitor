#pragma once

#include <QColor>
#include <QVector>
#include <QWidget>

class WaveformWidget final : public QWidget
{
    Q_OBJECT

public:
    explicit WaveformWidget(const QString &title, const QColor &color,
                            double minimum, double maximum, QWidget *parent = nullptr);

    void appendSample(double value);
    void appendSamples(const QVector<double> &values);
    void clearWaveform();
    void setLeadStatus(const QString &text, bool ok);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void ensureBuffer();

    QString m_title;
    QString m_status = QStringLiteral("已连接");
    QColor m_color;
    double m_minimum;
    double m_maximum;
    QVector<double> m_samples;
    QVector<bool> m_valid;
    int m_cursor = 0;
    bool m_statusOk = true;
};
