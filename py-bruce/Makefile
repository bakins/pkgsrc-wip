# $NetBSD$

DISTNAME=	bruce-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://bruce-tpt.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/bruce-tpt/
COMMENT= Bruce, the Presentation Tool, puts reStructuredText in your projector
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-cocos2d>=0.5.5:../../wip/py-cocos2d
DEPENDS+=	${PYPKGPREFIX}-pyglet>=1.1.4:../../wip/py-pyglet


USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
