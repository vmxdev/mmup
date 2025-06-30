AC_INIT([mmup], [25.06], [vm@xenoeye.com]) 

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([check-news foreign silent-rules subdir-objects -Wall])

AC_PROG_CC
LT_INIT

AC_MSG_CHECKING(whether compiler understands -Wall -Wextra -pedantic)
old_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Wall -Wextra -pedantic"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[])],
  AC_MSG_RESULT(yes),
  AC_MSG_RESULT(no)
  CFLAGS="$old_CFLAGS")


AC_SEARCH_LIBS([sin], [m], [], [
  AC_MSG_ERROR([unable to find the sin() function])
])

AM_SILENT_RULES([yes])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIRS([m4])
AC_OUTPUT
