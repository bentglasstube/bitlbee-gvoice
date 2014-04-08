AC_INIT([Google Voice plugin for BitlBee], 1.0, [alan@eatabrick.org], bitlbee-gvoice)
AC_PROG_CC
AC_PROG_INSTALL

AC_ARG_ENABLE([debug], AS_HELP_STRING([--enable-debug], [Enable debug support (default: disabled)]), debug=yes)
AC_MSG_CHECKING(for debug mode request)
if test "x$debug" = "xyes" ; then
	CFLAGS="-g -Wall -Werror"
	AC_MSG_RESULT(yes)
else
	AC_MSG_RESULT(no)
fi

case "`$CC -dumpmachine`" in
	*linux*|*freebsd*|*netbsd*|*openbsd*)
		SHARED_FLAGS="-fPIC -shared"
		SHARED_EXT="so"
		;;
	*apple-darwin*)
		SHARED_FLAGS="-dynamiclib -undefined dynamic_lookup"
		SHARED_EXT="dylib"
		;;
	*)
		AC_MSG_ERROR([Your machine is not yet supported])
		;;
esac
AC_SUBST(SHARED_FLAGS)
AC_SUBST(SHARED_EXT)

dnl Check for bitlbee
AC_MSG_CHECKING(for BitlBee)
if test -d /usr/local/lib/pkgconfig; then
	PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
	export PKG_CONFIG_PATH
fi
pkg-config --exists bitlbee
if test "$?" != "0"; then
	AC_MSG_RESULT(no)
	BITLBEE="no"
else
	AC_MSG_RESULT(yes)
	BITLBEE="yes"
	if test -z "$CFLAGS"; then
		CFLAGS="`pkg-config --cflags bitlbee`"
	else
		CFLAGS="$CFLAGS `pkg-config --cflags bitlbee`"
	fi
	if test -z "$LDFLAGS"; then
		LDFLAGS="`pkg-config --libs bitlbee`"
	else
		LDFLAGS="$LDFLAGS `pkg-config --libs bitlbee`"
	fi
	prefix=`pkg-config --variable=prefix bitlbee`
fi
AC_SUBST(BITLBEE)

if test "$BITLBEE" = "no"; then
	AC_ERROR([In order to use bitlbee-gvoice you need at least BitlBee installed.])
fi

AC_OUTPUT(config.mak)

echo "
	BitlBee plugin:                 $BITLBEE
	prefix:				$prefix
	install program:		$INSTALL"
if test "$BITLBEE" = "yes"; then
	echo "	compiler flags:			$CFLAGS
	linker flags:			$LDFLAGS
	shared object flags:		$SHARED_FLAGS
	shared object extension:	$SHARED_EXT"
fi
echo
