#ifndef MSGPACK_H
#define MSGPACK_H
#include <QByteArray>
#include <QVariantList>
#include "msgpack_common.h"
#include "msgpack_export.h"

namespace MsgPack
{
    MSGPACK_EXPORT QVariant unpack(const QByteArray &data);
    MSGPACK_EXPORT bool registerUnpacker(qint8 msgpackType, unpack_user_f unpacker);

    MSGPACK_EXPORT QByteArray pack(const QVariant &variant);
    MSGPACK_EXPORT bool registerPacker(QMetaType::Type qType, qint8 msgpackType, pack_user_f packer);

    MSGPACK_EXPORT void setCompatibilityModeEnabled(bool enabled);
}

#endif // MSGPACK_H
