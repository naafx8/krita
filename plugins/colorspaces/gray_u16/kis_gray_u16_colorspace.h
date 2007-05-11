/*
 *  Copyright (c) 2004-2006 Cyrille Berger <cberger@cberger.net>
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
#ifndef KIS_STRATEGY_COLORSPACE_GRAYSCALE_U16_H_
#define KIS_STRATEGY_COLORSPACE_GRAYSCALE_U16_H_
#include <QColor>

#include <klocale.h>
#include "pigment_gray_u16_export.h"
#include "KoLcmsColorSpace.h"
#include <KoColorSpaceTraits.h>

typedef KoColorSpaceTrait<quint16, 2, 1> GrayAU16Traits;

class PIGMENT_GRAY_U16_EXPORT KisGrayAU16ColorSpace : public KoLcmsColorSpace<GrayAU16Traits>
{
    public:
        KisGrayAU16ColorSpace(KoColorSpaceRegistry * parent, KoColorProfile *p);
        virtual bool willDegrade(ColorSpaceIndependence ) const { return false; }
};

class KisGrayAU16ColorSpaceFactory : public KoLcmsColorSpaceFactory
{
public:
    KisGrayAU16ColorSpaceFactory() : KoLcmsColorSpaceFactory(TYPE_GRAYA_16, icSigGrayData)
    {}
    virtual QString id() const { return "GRAYA16"; }
    virtual QString name() const { return i18n("Grayscale (16-bit integer/channel)"); }

    virtual KoColorSpace *createColorSpace(KoColorSpaceRegistry * parent, KoColorProfile *p) { return new KisGrayAU16ColorSpace(parent, p); };

    virtual QString defaultProfile() { return "gray built-in - (lcms internal)"; };
};

#endif // KIS_STRATEGY_COLORSPACE_GRAYSCALE_H_
