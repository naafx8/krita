/* This file is part of the KDE project
 * Copyright (C) 2017 Scott Petrovic <scottpetrovic@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#ifndef KIS_PAINTOP_PRESETS_SAVE_H
#define KIS_PAINTOP_PRESETS_SAVE_H

#include <QWidget>
#include <QDialog>

#include "ui_wdgsavebrushpreset.h"
#include "kis_canvas_resource_provider.h"

class KisPaintOpPresetSaveDialog : public QDialog , public Ui::WdgSaveBrushPreset
{
    Q_OBJECT



public:
    KisPaintOpPresetSaveDialog(QWidget* parent) : QDialog(parent) {
        setupUi(this);
    }
};


class KisPresetSaveWidget : public KisPaintOpPresetSaveDialog
{
    Q_OBJECT

public:
    KisPresetSaveWidget(QWidget* parent);
    virtual ~KisPresetSaveWidget();

    void showDialog();


    void scratchPadSetup(KisCanvasResourceProvider* resourceProvider);
    KisCanvasResourceProvider* m_resourceProvider;

public Q_SLOTS:
    void usePreviousThumbnail(bool usePrevious);
    void loadImageFromFile();
};


#endif
