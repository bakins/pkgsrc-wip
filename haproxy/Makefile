# $NetBSD: Makefile,v 1.10 2014/02/20 00:37:46 rodent Exp $

DISTNAME=	haproxy-1.5-dev22
PKGNAME=	haproxy-1.5b22
CATEGORIES=	net www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.5/src/devel/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://haproxy.1wt.eu/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
BUILD_MAKE_FLAGS+=	TARGET=${TARGET} USE_OPENSSL=1 USE_PRIVATE_CACHE=1
INSTALL_MAKE_FLAGS+=	TARGET=${TARGET}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

RCD_SCRIPTS=		haproxy
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
TARGET=netbsd
.elif ${OPSYS} == "FreeBSD"
TARGET=freebsd
.elif ${OPSYS} == "OpenBSD"
TARGET=openbsd
.elif ${OPSYS} == "SunOS"
TARGET=solaris
.elif ${OPSYS} == "Linux"
.  if !empty(OS_VERSION:M2.6.*)
TARGET=linux26
.  elif !empty(OS_VERSION:M2.4.*)
.    if exists(/usr/include/linux/eventpoll.h)
TARGET=linux24e
.    else
TARGET=linux24
.    endif
.  endif
.else
TARGET=generic
.endif

LIBS.SunOS+=		-lxnet

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg ${DESTDIR}${EGDIR}/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
