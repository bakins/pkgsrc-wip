# $NetBSD$
#

DISTNAME=	modplugplay-1.0
CATEGORIES=	audio
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/modplugplay/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://gnu.ethz.ch/linuks.mine.nu/modplugplay/
COMMENT=	Commandline music mod player using libmodplug
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

LDFLAGS+=	-lmodplug ${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	modplugplay.c
SUBST_SED.paths=	-e 's,@DEVOSSAUDIO@,${DEVOSSAUDIO},'

do-build:
	${CXX} ${WRKSRC}/modplugplay.c ${CFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/modplugplay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/modplugplay.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../mk/oss.buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
