# $NetBSD$

DISTNAME=	quodlibet-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://quodlibet.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/quodlibet/
COMMENT=	Finally a good alternative to iTunes
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins0.10-mad>=0.10.0:../../audio/gst-plugins0.10-mad
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.8:../../audio/py-mutagen
DEPENDS+=	gst-plugins0.10-vorbis>=0.10.0:../../audio/gst-plugins0.10-vorbis
DEPENDS+=	gst-plugins0.10-ogg>=0.10.0:../../multimedia/gst-plugins0.10-ogg

USE_TOOLS+=		msgfmt intltool
USE_PKGLOCALEDIR=	yes
BUILD_TARGET=		_trayicon.so _mmkeys.so

PYDISTUTILSPKG= yes
REPLACE_PYTHON=	exfalso.py quodlibet.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mutagen, py-gtk2, py-gstreamer0.10, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
