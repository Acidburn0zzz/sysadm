//===========================================
//  PC-BSD source code
//  Copyright (c) 2015, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef __PCBSD_LIB_UTILS_GENERAL_INCLUDES_H
#define __PCBSD_LIB_UTILS_GENERAL_INCLUDES_H

//Qt Includes
#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QTemporaryFile>

//FreeBSD Includes
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_media.h>

#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h> //from "man getnetent" (network entries)

#endif
