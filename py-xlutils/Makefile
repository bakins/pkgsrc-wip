# $NetBSD$

VERS=		1.4.1
DISTNAME=	xlutils-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/x/xlutils/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.simplistix.co.uk/software/python/xlutils
COMMENT=	Utilities for working with Excel files
LICENSE=	mit

DEPENDS+=      ${PYPKGPREFIX}-xlrd>=0.7.1:../../textproc/py-xlrd
DEPENDS+=      ${PYPKGPREFIX}-xlwt>=0.7.1:../../textproc/py-xlwt

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-xlwt

.include "../../lang/python/egg.mk"
.include "../../wip/py-errorhandler/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
