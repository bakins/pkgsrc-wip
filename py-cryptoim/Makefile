# $NetBSD$

DISTNAME=	CryptoIM-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	security
MASTER_SITES=	https://pypi.python.org/packages/source/C/CryptoIM/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/CryptoIM/
COMMENT=	Crypto Instant Messenger
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-coveralls>=2.4.2:../../wip/py-coveralls
DEPENDS+=	${PYPKGPREFIX}-sleekxmpp>=1.1.11:../../wip/py-sleekxmpp

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
