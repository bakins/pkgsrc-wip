# $NetBSD$

DISTNAME=	Forthon-0.8.13
PKGNAME=        ${PYPKGPREFIX}-forthon-0.8.13
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://hifweb.lbl.gov/Forthon/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hifweb.lbl.gov/Forthon/
COMMENT=	Fortran95 wrapper/code development package
LICENSE=	modified-bsd


WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c fortran

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/Forthon ${WRKSRC}/Forthon${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
