/*
 * Copyright (C) 2021 CutefishOS Team.
 *
 * Author:     cutefishos <cutefishos@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "controlcenterdialog.h"
#include <KWindowSystem>

ControlCenterDialog::ControlCenterDialog(QQuickView *parent)
    : QQuickView(parent)
{
    setFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    connect(this, &QQuickView::activeChanged, this, [=] {
        if (!isActive())
            hide();
    });
}

void ControlCenterDialog::showEvent(QShowEvent *event)
{
    KWindowSystem::setState(winId(), NET::SkipTaskbar | NET::SkipPager | NET::SkipSwitcher);
    QQuickView::showEvent(event);
}

void ControlCenterDialog::hideEvent(QHideEvent *event)
{
    QQuickView::hideEvent(event);
}
