# $NetBSD$
#

DISTNAME=	eyeD3-0.6.18
PKGNAME=	${PYPKGPREFIX}-eyed3-0.6.18
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://eyed3.nicfit.net/releases/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://eyed3.nicfit.net/
COMMENT=	Python module for id3-tags manipulation
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26
PY_PATCHPLIST=	yes

REPLACE_PYTHON+=		bin/eyeD3

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
