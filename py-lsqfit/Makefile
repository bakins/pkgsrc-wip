# $NetBSD$

DISTNAME=	lsqfit-4.8
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lsqfit/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	  https://github.com/gplepage/lsqfit.git
COMMENT=	Utilities for nonlinear least-squares fits
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
