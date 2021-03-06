#include "msgpack.h"
#include "private/unpack_p.h"
#include "private/pack_p.h"
#include <QByteArray>

QVariant MsgPack::unpack(const QByteArray &data)
{
    quint8 *p = (quint8 *)data.data();
    quint8 *end = p + data.size() - 1;

    return MsgPackPrivate::unpack(p, end);
}

QByteArray MsgPack::pack(const QVariant &variant)
{
    quint8 *p = 0;
    quint8 *end = MsgPackPrivate::pack(variant, p, false);
    quint32 size = end - p;
    //qDebug() << "size probe:" << size;

    QByteArray arr;
    arr.resize(size);
    end = MsgPackPrivate::pack(variant, (quint8 *)arr.data(), true);

    return arr;
}

bool MsgPack::registerPacker(QMetaType::Type qType, qint8 msgpackType, MsgPack::pack_user_f packer)
{
    return MsgPackPrivate::register_packer(qType, msgpackType, packer);
}

bool MsgPack::registerUnpacker(qint8 msgpackType, MsgPack::unpack_user_f unpacker)
{
    return MsgPackPrivate::register_unpacker(msgpackType, unpacker);
}

void MsgPack::setCompatibilityModeEnabled(bool enabled)
{
    MsgPackPrivate::compatibilityMode = enabled;
}
