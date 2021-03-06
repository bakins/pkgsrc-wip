# $NetBSD: Makefile,v 1.16 2013/07/15 02:02:28 ryoon Exp $

# the Git SHA1 ID of the snapshot
OPENSC_GIT_REVISION=	a399905d234d3d6d2a9aa8501a4c8ba1224c6b31
# this suffix is what is generated by the '-S' option to './bootstrap'
# (when run from a Git clone of the OpenSC repository)
OPENSC_VERSION_SUFFIX=	git20140221130957
# this revision is what is generated by the '-R' option to './bootstrap'
# (when run from a Git clone of the OpenSC repository)
OPENSC_VERSION_REVISION=	220
OPENSC_PKG_VERSION=	0.13.0${OPENSC_VERSION_SUFFIX}
DISTNAME=		opensc-${OPENSC_PKG_VERSION}
CATEGORIES=		security
MASTER_SITES=		-https://github.com/OpenSC/OpenSC/archive/${OPENSC_GIT_REVISION}.tar.gz
WRKSRC=			${WRKDIR}/OpenSC-${OPENSC_GIT_REVISION}

MAINTAINER=		rhansen@bbn.com
HOMEPAGE=		https://github.com/OpenSC/OpenSC/wiki
COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=		gmake pkg-config

USE_TOOLS+=		autoreconf autoconf automake
AUTOCONF_REQD=		2.60
AUTOMAKE_REQD=		1.10
pre-configure:
	cd ${WRKSRC:Q} && \
	./bootstrap \
		-s ${OPENSC_VERSION_SUFFIX:Q} \
		-r ${OPENSC_VERSION_REVISION:Q}

.include "options.mk"

# Previous versions needed these, but 0.12.2 configure does not
# recognize them.
#CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
#CONFIGURE_ARGS+=	--disable-sensitive-logging

# Is this necessary (and non-default)?
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

# This is perhaps an upstream bug.
CONFIGURE_ENV+=		PCSC_CFLAGS=-I${PREFIX}/include/PCSC

# The stylesheets are not found without this.
CONFIGURE_ARGS+=	--with-xsl-stylesheetsdir=${BUILDLINK_PREFIX.docbook-xsl}/share/xsl/docbook

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

# build tools for doc; should be TOOLS
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/docbook-xsl/buildlink3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
