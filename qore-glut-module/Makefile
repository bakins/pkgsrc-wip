# $NetBSD$

DISTNAME=	qore-glut-module-0.0.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	GLUT Qore bindings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

CONFIGURE_ARGS+=--with-glut=${BUILDLINK_PREFIX.glut}

.include "options.mk"

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../wip/qore-opengl-module/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
