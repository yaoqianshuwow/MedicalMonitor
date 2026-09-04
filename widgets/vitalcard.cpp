#include "vitalcard.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

VitalCard::VitalCard(const QString &title, const QString &unit,
                     const QColor &color, QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("vitalCard"));
    setMinimumHeight(102);

    auto *titleLabel = new QLabel(title, this);
    titleLabel->setStyleSheet(QStringLiteral("color:%1;font-size:15px;font-weight:600;").arg(color.name()));
    auto *unitLabel = new QLabel(unit, this);
    unitLabel->setStyleSheet(QStringLiteral("color:#9eb0b8;font-size:11px;"));
    m_valueLabel = new QLabel(QStringLiteral("--"), this);
    m_valueLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_valueLabel->setStyleSheet(QStringLiteral("color:%1;font-size:38px;font-weight:700;").arg(color.name()));
    m_secondaryLabel = new QLabel(QStringLiteral("状态：等待数据"), this);
    m_secondaryLabel->setStyleSheet(QStringLiteral("color:#9eb0b8;font-size:11px;"));

    auto *header = new QHBoxLayout;
    header->addWidget(titleLabel);
    header->addStretch();
    header->addWidget(unitLabel);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(12, 8, 12, 8);
    layout->setSpacing(1);
    layout->addLayout(header);
    layout->addWidget(m_valueLabel, 1);
    layout->addWidget(m_secondaryLabel);
}

void VitalCard::setValue(const QString &value)
{
    m_valueLabel->setText(value);
}

void VitalCard::setSecondaryText(const QString &text)
{
    m_secondaryLabel->setText(text);
}
