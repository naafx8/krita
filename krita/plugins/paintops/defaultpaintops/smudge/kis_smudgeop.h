/*
 *  Copyright (c) 2002 Patrick Julien <freak@codepimps.org>
 *  Copyright (c) 2004-2008 Boudewijn Rempt <boud@valdyas.org>
 *  Copyright (c) 2004 Clarence Dang <dang@kde.org>
 *  Copyright (c) 2004 Adrian Page <adrian@pagenet.plus.com>
 *  Copyright (c) 2004 Cyrille Berger <cberger@cberger.net>
 *  Copyright (c) 2010 José Luis Vergara Toloza <pentalis@gmail.com>
 *  Copyright (C) 2011 Silvio Heinrich <plassy@web.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef KIS_SMUDGEOP_H_
#define KIS_SMUDGEOP_H_

#include <KoColorSpace.h>

#include "kis_brush_based_paintop.h"
#include <kis_types.h>
#include <kis_pressure_size_option.h>
#include <kis_pressure_rate_option.h>
#include <kis_merged_paint_option.h>

class KisBrushBasedPaintOpSettings;

class QPointF;
class KisPainter;

class KisSmudgeOp : public KisBrushBasedPaintOp
{
public:
    KisSmudgeOp(const KisBrushBasedPaintOpSettings *settings, KisPainter * painter, KisImageWSP image);
    virtual ~KisSmudgeOp();

    qreal paintAt(const KisPaintInformation& info);

private:
    bool                  m_firstRun;
    KisPaintDeviceSP      m_tempDev; // The temporary paint device
    KisImageWSP           m_image;
    KisPainter*           m_tempPainter;
    KisPressureSizeOption m_sizeOption;
    KisPressureRateOption m_smudgeRateOption;
    KisPressureRateOption m_colorRateOption;
    KisMergetPaintOption  m_mergedPaintOption;
};

#endif // KIS_SMUDGEOP_H_
