#ifndef _OSMAND_CORE_OBF_DATA_INTERFACE_H_
#define _OSMAND_CORE_OBF_DATA_INTERFACE_H_

#include <OsmAndCore/stdlib_common.h>
#include <array>
#include <functional>

#include <OsmAndCore/QtExtensions.h>
#include <QList>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Map/MapTypes.h>
#include <OsmAndCore/Data/ObfMapSectionReader.h>

namespace OsmAnd
{
    class ObfReader;
    class ObfFile;
    class ObfMapSectionInfo;
    namespace Model
    {
        class BinaryMapObject;
    }
    class IQueryController;
    namespace ObfMapSectionReader_Metrics
    {
        struct Metric_loadMapObjects;
    }

    class OSMAND_CORE_API ObfDataInterface
    {
        Q_DISABLE_COPY(ObfDataInterface);
    private:
    protected:
    public:
        ObfDataInterface(const QList< std::shared_ptr<const ObfReader> >& obfReaders);
        virtual ~ObfDataInterface();

        const QList< std::shared_ptr<const ObfReader> > obfReaders;

        bool loadObfFiles(
            QList< std::shared_ptr<const ObfFile> >* outFiles = nullptr,
            const IQueryController* const controller = nullptr);

        bool loadBasemapPresenceFlag(
            bool& outBasemapPresent,
            const IQueryController* const controller = nullptr);

        bool loadMapObjects(
            QList< std::shared_ptr<const OsmAnd::Model::BinaryMapObject> >* resultOut,
            MapFoundationType* foundationOut,
            const AreaI& area31,
            const ZoomLevel zoom,
            const FilterMapObjectsByIdFunction filterById = nullptr,
            ObfMapSectionReader::DataBlocksCache* cache = nullptr,
            QSet<ObfMapSectionReader::DataBlockId>* outReferencedCacheEntries = nullptr,
            const IQueryController* const controller = nullptr,
            ObfMapSectionReader_Metrics::Metric_loadMapObjects* const metric = nullptr);
    };
}

#endif // !defined(_OSMAND_CORE_OBF_DATA_INTERFACE_H_)