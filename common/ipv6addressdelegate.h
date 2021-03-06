/*
Copyright (C) 2010 Srivats P.

This file is part of "Ostinato"

This is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#ifndef _IPV4_ADDRESS_DELEGATE
#define _IPV4_ADDRESS_DELEGATE

#include "ipv6addressvalidator.h"

#include <QItemDelegate>
#include <QLineEdit>

class IPv6AddressDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    IPv6AddressDelegate(QObject *parent = 0);
    ~IPv6AddressDelegate();

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, 
            const QModelIndex &index) const;
};

inline IPv6AddressDelegate::IPv6AddressDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

inline IPv6AddressDelegate::~IPv6AddressDelegate()
{
}

inline QWidget* IPv6AddressDelegate::createEditor(QWidget *parent, 
        const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *ipEdit;

    ipEdit = static_cast<QLineEdit*>(QItemDelegate::createEditor(
                parent, option, index));

    ipEdit->setValidator(new IPv6AddressValidator(ipEdit));

    return ipEdit;
}
#endif

