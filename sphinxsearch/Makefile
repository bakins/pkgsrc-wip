# $NetBSD$
#

DISTNAME=	sphinx-2.1.6-release
PKGNAME=	${DISTNAME:S/-/search-/:S/-release//}
CATEGORIES=	databases textproc
MASTER_SITES=	http://sphinxsearch.com/files/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.sphinxsearch.com/
COMMENT=	Sphinx Full-Text Search Engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

SPHINX_USER?=	sphinx
SPHINX_GROUP?=	sphinx
SPHINX_DIR?=	${VARBASE}/db/sphinx
SPHINX_RUN?=	${VARBASE}/spool/sphinx
SPHINX_LOG?=	${VARBASE}/log/sphinx

.include "options.mk"

EGDIR=		${PREFIX}/share/examples/sphinx
CONF_FILES+=	${EGDIR}/sphinx-min.conf ${PKG_SYSCONFDIR}/sphinx.conf

INSTALLATION_DIRS=	bin sbin ${EGDIR}
OWN_DIRS+=		${SPHINX_DIR} ${SPHINX_RUN} ${SPHINX_LOG}
OWN_DIRS_PERMS+=	${SPHINX_DIR} ${SPHINX_USER} ${SPHINX_GROUP} 0770
OWN_DIRS_PERMS+=	${SPHINX_RUN} ${SPHINX_USER} ${SPHINX_GROUP} 0770
OWN_DIRS_PERMS+=	${SPHINX_LOG} ${SPHINX_USER} ${SPHINX_GROUP} 0770

PKG_GROUPS+=		${SPHINX_GROUP}
PKG_USERS+=		${SPHINX_USER}:${SPHINX_GROUP}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	sphinx.conf.in sphinx-min.conf.in Makefile.in src/searchd.cpp
SUBST_FILES.paths+=	src/Makefile.in
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/searchd.pid,${SPHINX_RUN}/searchd.pid,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/query.log,${SPHINX_LOG}/query.log,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/searchd.log,${SPHINX_LOG}/searchd.log,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@,${SPHINX_DIR},g'
SUBST_SED.paths+=	-e 's,@localstatedir@,${SPHINX_DIR},g'
SUBST_SED.paths+=	-e 's,@egdir@,${EGDIR},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'

FILES_SUBST+=		SPHINX_USER=${SPHINX_USER}
FILES_SUBST+=		SPHINX_GROUP=${SPHINX_GROUP}

CONFIGURE_DIRS=		.
CONFIGURE_DIRS+=	api/libsphinxclient

CONFIGURE_ARGS+=        --with-iconv

MAKE_JOBS_SAFE=		no
LIBS.SunOS+=		-liconv -lsocket -lnsl

post-install:
	${MV} ${DESTDIR}${EGDIR}/sphinx.conf.dist ${DESTDIR}${EGDIR}/sphinx-full.conf
	${MV} ${DESTDIR}${EGDIR}/sphinx-min.conf.dist ${DESTDIR}${EGDIR}/sphinx-min.conf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
