# $NetBSD$
#

DISTNAME=		siege-2.78
CATEGORIES=		www
MASTER_SITES=		http://www.joedog.org/pub/siege/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://www.joedog.org/JoeDog/Siege
COMMENT=		Website/webserver regression testing utility
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		autoconf

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/siege
CONF_FILES=		${EGDIR}/urls.txt ${PKG_SYSCONFDIR}/urls.txt

SUBST_CLASSES+=		siege
SUBST_STAGE.siege=	post-patch
SUBST_FILES.siege=	doc/Makefile.am doc/Makefile.in
SUBST_SED.siege+=	-e "s|@EGDIR@|${EGDIR}|g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		PERL=${PERL5:Q}

INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
