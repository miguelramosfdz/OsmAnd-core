#include "MapMarker.h"
#include "MapMarker_P.h"

OsmAnd::MapMarker::MapMarker(
    const int baseOrder_,
    const std::shared_ptr<const SkBitmap>& pinIcon_,
    const QHash< OnSurfaceIconKey, std::shared_ptr<const SkBitmap> >& onMapSurfaceIcons_,
    const bool isAccuracyCircleSupported_,
    const FColorRGB accuracyCircleBaseColor_)
    : _p(new MapMarker_P(this))
    , baseOrder(baseOrder_)
    , pinIcon(pinIcon_)
    , onMapSurfaceIcons(onMapSurfaceIcons_)
    , isAccuracyCircleSupported(isAccuracyCircleSupported_)
    , accuracyCircleBaseColor(accuracyCircleBaseColor_)
{
}

OsmAnd::MapMarker::~MapMarker()
{
}

bool OsmAnd::MapMarker::isHidden() const
{
    return _p->isHidden();
}

void OsmAnd::MapMarker::setIsHidden(const bool hidden)
{
    _p->setIsHidden(hidden);
}

bool OsmAnd::MapMarker::isAccuracyCircleVisible() const
{
    return _p->isAccuracyCircleVisible();
}

void OsmAnd::MapMarker::setIsAccuracyCircleVisible(const bool visible)
{
    _p->setIsAccuracyCircleVisible(visible);
}

double OsmAnd::MapMarker::getAccuracyCircleRadius() const
{
    return _p->getAccuracyCircleRadius();
}

void OsmAnd::MapMarker::setAccuracyCircleRadius(const double radius)
{
    _p->setAccuracyCircleRadius(radius);
}

OsmAnd::PointI OsmAnd::MapMarker::getPosition() const
{
    return _p->getPosition();
}

void OsmAnd::MapMarker::setPosition(const PointI position)
{
    _p->setPosition(position);
}

float OsmAnd::MapMarker::getOnMapSurfaceIconDirection(const OnSurfaceIconKey key) const
{
    return _p->getOnMapSurfaceIconDirection(key);
}

void OsmAnd::MapMarker::setOnMapSurfaceIconDirection(const OnSurfaceIconKey key, const float direction)
{
    _p->setOnMapSurfaceIconDirection(key, direction);
}

OsmAnd::ColorARGB OsmAnd::MapMarker::getPinIconModulationColor() const
{
    return _p->getPinIconModulationColor();
}

void OsmAnd::MapMarker::setPinIconModulationColor(const ColorARGB colorValue)
{
    _p->setPinIconModulationColor(colorValue);
}

bool OsmAnd::MapMarker::hasUnappliedChanges() const
{
    return _p->hasUnappliedChanges();
}

bool OsmAnd::MapMarker::applyChanges()
{
    return _p->applyChanges();
}

std::shared_ptr<OsmAnd::MapSymbolsGroup> OsmAnd::MapMarker::createSymbolsGroup() const
{
    return _p->createSymbolsGroup();
}
