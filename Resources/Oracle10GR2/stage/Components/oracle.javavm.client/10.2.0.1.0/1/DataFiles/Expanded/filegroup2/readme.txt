Oracle10i Release 1 (10.1.0) Java Virtual Machine README

Table of Contents

1.     Oracle's Enterprise Java Server Platform -- OracleJVM
1.1    Documentation
1.2    Getting Started
1.3    What's New in this Release
1.4    Configuration
1.5    Java Compatibility
1.6    Compatibility Mode
2.     Known Problems
2.1    Memory Usage
2.2    Accessibility of Server-Resident Java Source
2.3    DESCRIBE Problems with Java
2.4    Loadjava and Dropjava
2.5    Error Reporting
2.6    java.version, oracle.jserver.version, and oracle.server.version
2.7    Bug #895586 -- Multibyte Character Output Truncation at 255 Bytes
2.8    Bug #1330979 -- Wrong Japanese error message returned in SQLException
       in Java
2.9    Bug #1001690 -- Exception thrown when attaching JDB for debugging
2.10   Java Calling SQL and Vice Versa
2.11   Java and PL/SQL
2.12   Examples
2.13   SSL Limitations
3.     Natively Compiled Java Code
3.1    Upgrade, Downgrade, Import, Export
3.2    Security
3.3    Acceptable C Compiler Versions
3.4    Known issues


1. Oracle's Enterprise Java Server Platform -- OracleJVM

Oracle10i Release 1 (10.1.0) includes a fully functional Java virtual
machine (VM), as well as the Java class libraries for Sun's Java
Development Kit (JDK) 1.4.  When combined with Oracle's JDBC and
SQLJ, this release provides an enterprise class platform, OracleJVM,
for developing and deploying server-based Java applications.

1.1  Documentation

Separate hardcopy and on-line documentation are provided for the major
Java-related components of this release.

- Oracle10i Java Developer's Guide
- Oracle10i JDBC Developer's Guide and Reference
- Oracle10i SQLJ Developer's Guide and Reference
- Oracle10i JPublisher User's Guide

The Oracle10i Java Developer's Guide provides an overview of all Java
products and is an excellent starting point for exploring the Java
capabilities of Oracle10i.
 
Please refer to these documents and their respective README files for
detailed information on each area.  Information on JVM and NComp
information is covered in this README file.

1.2  Getting Started

We recommend that you follow the examples presented in the Oracle10i
Java Developer's Guide to begin.  The demonstrations and examples in
ORACLE_HOME/javavm/demo include a HelloWorld example for Java Stored
Procedures.  Execution of this and other examples will ensure that
your installation was complete and that OracleJVM is properly
enabled in your database.

1.3  What's New in this Release?

There are a number of changes and new features for the OracleJVM in
Oracle10i Release 1:
- The system classes in Oracle JVM are upgraded from JDK 1.3 level to
JDK 1.4.
- The memory model for dedicated mode sessions has changed.  As a
result, process specifc resources such as threads can now live across
database calls for dedicated mode sessions.
- In Oracle10i, you can use the OracleJVM to call out to external
Web Services from Java and PL/SQL.
- Oracle10i provides a new native Java interface to call Java classes
in OracleJVM directly without defining a PL/SQL callspec.

For more details on these new features, please refer to the Oracle10i
Java Developer's Guide.

1.4  Configuration

The Oracle10i Java Developer's Guide provides details of installing
and configuring a Java-enabled database. The primary init.ora
parameters that can affect Java usage and performance are
shared_pool_size and java_pool_size.  

The memory specified in shared_pool_size is consumed transiently
during use of loadjava.  The database initialization process (i.e.,
executing initjvm.sql against a clean database, as opposed to the
installed seed database) requires shared_pool_size to be set to 50MB
as it loads the Java binaries for approximately 8000 classes and
resolves them.  Shared_pool resource is also consumed as
call-specifications are defined, and as dynamically loaded Java
classes are tracked at runtime.

All other Java state during runtime execution of Java is taken from
the amount allocated using java_pool_size.  This memory includes the
shared in-memory representation of Java method and class definitions,
as well as the Java objects that are migrated to session space at
end-of-call.  In the former case, the memory cost is shared among all
users.  In the latter case, in MTS mode, you will need to adjust
java_pool_size allocations based on the actual amount of state held in
static variables for each session.

As in Sun's JDK, the Java compiler (i.e., the compiler, written in
Java, that compiles Java source code to Java binaries) is known to be
a voracious consumer of memory.  If you intend to compile significant
amounts of Java source on the OracleJVM, or you will be deploying
complex EJB's (which use the Compiler on the server), you should
consider increasing java_pool_size.  The default value for
java_pool_size is 20MB.

1.5  Java Compatibility

This release has been thoroughly tested with Sun's Java Compatibility
Kit for the JDK 1.4.1. Oracle is committed to OracleJVM keeping pace
with Java and other Internet standards.

1.6  Compatibility Mode

To use Java in the OracleJVM server, you must set

    compatibility = 8.1.0

or higher.


2.  Known Problems

The following known problems encompass the VM itself, Java Stored
Procedures, and the utilities used by most Java developers, loadjava
and dropjava.  Java interaction with SQL, particularly known problems
with support for SQL-Java type translations, are discussed in the JDBC
README.

2.1  Memory Usage

Java introduces a significant development-time vs. runtime memory
usage difference that is not reflected in the installation-time
configuration assistance that is provided.  Specifically, the
installed configuration is limited to minimum, typical, and custom
installs, but there is no means in this release of querying at install
time to determine how you anticipate using Java.

During development of OracleJVM applications, you will be using tools
such as loadjava, which consume memory in different ways than a
runtime Java application.  These tools are development-time only tools
and do not enter into the world of runtime applications.  As discussed
in the Java Developer's Guide, you may choose a style of development
using a client-side IDE, or you may choose to use the Java compiler on
the OracleJVM.  The Compiler, which is adapted from Sun's JDK compiler,
is very memory-intensive, and may require you to increase
java_pool_size from the installed configuration value.

The following rules of thumb apply:

    - You will need more java_pool_size if you are compiling code on
      the server than if you are compiling on the client and loading
      to the server.  EJB deployment uses the Java compiler on the
      server, and therefore requires java_pool_size to be large.

    - You will need more shared_pool_size to handle loading large
      numbers of classes to the server and resolving them.

    - Under MTS, you will need to increase java_pool_size based on
      both the number of sessions and the amount of memory held in
      Java static variables at end-of-call.

    - Your runtime memory requirements at runtime will most likely be
      different than those required for Java development.  If you are
      doing Java development, we recommend the following settings:

    shared_pool_size = 50000000
    java_pool_size = 20000000

These are the default installation values for the OracleJVM
custom install.

If you are deploying a Java application, the memory requirements will
be dependent on the application itself and the number of users
executing it concurrently.

2.1.1 Insufficient Memory or Resources During initjvm.sql Execution

If initjvm.sql executed properly, the total count of Java schema
objects should be greater than 8,000, as shown by:

    connect internal
    select count (*) from user_objects where object_type='JAVA CLASS';

All classes should be marked VALID, so the number of invalid classes
should be zero, as shown by:

    select count(*) from user_objects 
       where object_type='JAVA CLASS' and status != 'VALID';

If initjvm failed you should check your init.ora file to ensure that
the shared_pool_size and java_pool_size are at least 50MB and 20MB
respectively.  These values may be set incorrectly if you chose the
minimal or typical installation, which assumes you are starting with a
Java-enabled database.

2.1.2  Insufficient Memory During Java Class Loading

When shared_pool_size is too low to handle the creation of class
schema objects, the operation may fail silently, leaving invalid
classes in the database.  During subsequent runtime execution, the
system will attempt to resolve any classes that are not VALID.  If it
is unsuccessful, you may see a ClassNotFoundException or a
NoClassDefFoundException at runtime.  Note that these are valid runtime
exceptions that can occur because you failed to install a class on the
server.  They do not necessarily indicate there was any problem with
shared_pool_size during loading.  You should always verify that the
class was included in the set you are loading to the server, and you
should consider using the -force option of loadjava to force the class
you're loading to replace the server-resident one.

Use the -resolve options of loadjava to request that loadjava attempt
resolution of a class when it is loaded. Normally loadjava will print
error messages when resolution fails. If these messages indicate a
memory problem or failures such as "connection lost", you can increase
the size of shared_pool_size and java_pool_size and try again.

To double check the status of a class that you have created with
loadjava, you can connect to the database in the schema containing the
class and do:

    select * from user_objects where object_name = 
        dbms_java.shortname('<classname>') ;

Among the columns of user_objects is a status.

2.3  DESCRIBE Problems with Java

DESCRIBE of package.procedure gives "object does not exist" when the
method has a Java rather than PL/SQL implementation.  DESCRIBE of
package lists only PL/SQL procedures and excludes the Java Stored
Procedures.

2.4  Loadjava and Dropjava

Loadjava and Dropjava are java-based utilities you run on the
client-side to load java binaries, source, or jar files to the server,
and to drop the corresponding libunits.  They are documented in the
hardcopy as well as the online documentation (e.g., the Oracle10i Java
Developer's Guide).

2.4.1 We recommend that you not load source and binaries together in a
jar file.  You cannot load source (.java) and binary (.class) files
for the same class in the same jar file.

2.4.2 An important aspect of Java is its support for a binary
standard.  The Java binary standard allows you to do client-side
development and only load the Java binaries to the server.  You may
find that use of a client-side compiler and loadjava to load the
resulting binaries provides better performance than use of loadjava
with source.

2.4.4 It would be desirable to allow dropjava to drop a package, but
no such capability exists.

2.4.5 Loading large jar files may require additional shared_pool.  The
creation of java schema objects consumes memory specified in
shared_pool_size.  If you experience a problem loading large jar
files, consider increasing the value of SHARED_POOL_SIZE as a
workaround.

If you feel that there is a problem with loadjava having not properly
loaded and resolved a class, you can examine the state of loaded
classes by connecting as the user who loaded the class (e.g.,
scott/tiger) and executing:

    select * from user_objects;

Properly loaded and resolved classes should show up with status of
VALID.  A shorthand alternative to determine if any classes are not
VALID is:

    select dbms_java.longname(object_name) from user_objects 
       where object_type = 'JAVA CLASS' and status != 'VALID';

2.5  Error Reporting

Errors are often reported in a trace file.  Please examine the trace
file as your first step in isolating problems.

2.6 java.version, oracle.jserver.version, and oracle.server.version

In release 10.1.0, we return "1.4.1" for java.version property, to
correspond to the JDK default. If you have been using the presence of
"Oracle" in java.version to determine whether your code is running on
OracleJVM as opposed to the client, then you should switch to testing
whether the oracle.jserver.version property is non-null.  (In release
8.1.5, the value of java.version was "Oracle Server 1.1.6". In release
8.1.6, 8.1.7 and 9.0.1 the value of java.version was "1.2.1". In
release 9.2.0, the value of java.version was "1.3.1".)  The property
oracle.server.version is now deprecated.  It was set in 8.1.5,
8.1.6 and 8.1.7 for backward compatibility reasons only.

2.7 Bug #895586 -- Multibyte Character Output Truncation at 255 Bytes

If you use dbms_java.set_output to redirect System.out.println() to
standard output, and the 255th byte is part of a multibyte character,
this character will be broken into 2 one byte characters in the
output.  The workaround is to break your output into smaller pieces.

2.8 Bug #1330979 -- Wrong Japanese error message returned in
SQLException in Java

If you are using multi byte character set, the exception message
returned by java.sql.SQLException may be mangled.

2.9 Bug #1001690 -- Exception thrown when attaching JDB for debugging

When doing a call to DBMS_JAVA.START_DEBUGGING() and attaching with
JDB, a java.security.AccessControlException is thrown if you do not
have the required permissions. To grant these permissions to a user,
you need to do:

SQL> call dbms_java.grant_permission('SCOTT', 'SYS:oracle.aurora.security.JServerPermission', 'Debug', null);

To confirm that this permission is in effect, you can do:
SQL> select type_name, name, enabled from user_java_policy where type_name like '%JServerPermission%';

and should see Debug/ENABLED among the granted JServerPermission types.

2.10  Java Calling SQL and Vice Versa

Please refer to the JDBC README for details on limitations in "SQL
Call-in".  There are known problems with usage of some data types and
their translation between Java and SQL.  In general, these are not
JDBC problems, but are the responsibility of the Aurora runtime
machinery.  We have chosen to document the problems in the JDBC README
(ORACLE_HOME\jdbc\readme.txt) because JDBC users are the most likely
to encounter the problems.

2.11  Java and PL/SQL

Refer to the "Java Stored Procedures" documentation for details of
PL/SQL and Java interaction.  It is a known feature of call-spec
definition that there is no checking at definition time between the
method signature provided in the call-spec and the method which will
be invoked at runtime.  The design is such that mismatches are only
detected at runtime.

2.12 Examples
We provide numerous examples showing how to use Java Stored
Procedures.  The examples can be found under
ORACLE_HOME/javavm/demo. 

Before running these examples, you need to have the JDK commands for
java, javac in your PATH as decribed above in 3.13. You also need to
have ORACLE_HOME, CLASSPATH, JAVA_HOME, LD_LIBRARY_PATH set
correctly. Lastly, you should check the values for java_pool_size and
shared_poll_size, in the init.ora file. These should be at least 50mb
each.

Also note that within each Makefile, there are two different
classpaths defined - one for JDK1.1.x and one for JDK1.2. Before
running an example, you should edit the Makefile (or batchfiles on NT)
and verify that the relevant MAKE_CLASSPATH for your JDK installation
is uncommented.

All the samples should work, without any modifications, as described
in their individual readme. Please do read the readme, as some of the
preparations include things like creating a demo user "CLERK", before
being able to run. 

2.13 SSL Limitations

2.13.1 Using SSL client side authentication when making an SSL callout
from one server into another server is not supported in this release.

2.13.2 In this release, "SSL_CREDENTIAL" login is not supported. For
example, the code:

    env.put (Context.SECURITY_AUTHENTICATION, ServiceCtx.SSL_CREDENTIAL)

does not work and should be replaced with:

    env.put (Context.SECURITY_AUTHENTICATION, ServiceCtx.SSL_LOGIN)


3.  JAccelerator ("NComp"). Natively Compiled Java Code

This release contains all core Java classes, plus the JDBC, and SQLJ
Java classes in natively compiled form.  (Note: swing and awt classes,
which are included only for compatibility on the server, are not
natively compiled).  As described in the Java Developer's Guide, the
natively compiled code is dynamically opened at runtime using shared
object libraries from the ORACLE_HOME/javavm/admin directory.

3.1 Upgrade, Downgrade, Import, Export

Java code that you natively compile in this release will not be
automatically upgraded in future Oracle releases.  To move to a new
Oracle release, you will need to upgrade and then natively compile the
code again in the upgraded server.  Similarly, import and export of
Java code between Oracle databases does not include the natively
compiled form of your Java code.  In these cases, as long as the O/S
and platform are the same, you should redeploy the deployment jar
files that you created originally to install natively compiled Java
code in another location.

3.2 Security

Deployment of natively compiled code in the server is protected by a
Java privilege, as described in the documentation.  You should
understand that this privilege should only be granted when the party
installing or supplying the natively compiled code is well-known and
trusted.  The code generation process employed to produce the shared
libraries is provided by and tested extensively by Oracle; however,
unlike interpreted Java code and PL/SQL programs, native code is
executed from shared libraries that are dynamically opened at runtime.
The right to install such shared libraries should be closely
controlled.

3.3 Acceptable C Compiler Versions

Please review the Settings_os.properties file on your platform to
determine what C compiler Oracle has certified for supported use
with OracleJVM Accelerator in this release.  Oracle has continuing
work to certify more C compilers against this and future releases and
will make such information available on Oracle Technology Network on
an ongoing basis.

3.4 Known issues

3.4.1  C compiler out of memory during C compilation

During compilation of very large packages, C compilers may be getting
out of memory. You can switch to the non-bundling mode, compiling each
class separately, by omitting

makefile.maker = $(one.c.unit.per.dll.makefile.maker)

in files 
  javavm/jahome/Settings_solaris.properties
and
   javavm/jahome/Settings_sunos.properties


3.4.2 KNOWN BUG: Having a dot in directory name of deployment jar
aborts deployment

If you pass a full-path deployment jar name to deploync, you'll get
incorrect results if the directories in the path or the deployment jar
contain '.':

 deploync ... /foo.bar/mydepl.jar
 deploync ... /foo_bar/my.depl.jar

 Workaround(1) avoid using '.' in directories  and jar names, 
 Workaround(2): use -d:

 deploync ... -d /foo.bar mydepl.jar

3.4.3 Half of my package previously ncomped now is not!

If your app is in 2 jars, and for package P half of its classes are in
the first jar and half in the second, then after ncomping the second
jar you'll find the classes from the first jar un-ncomped. This is
because ncomp deploys dlls on a per-package basis. 

To avoid such situations, structure the source jars in such way that
all classes for a given package P are in a single jar. This also
offers the best possible performance.

3.4.4  All toplevels are in the same package UnnamedPackage!

Beware of toplevel classes: if you have a toplevel class X, previously
ncomped, and then you separately ncomped a toplevel class Y, X will
become un-ncomped. This is because all toplevel classes are considered
in a special package "UnnamedPackage".

3.4.5  "nothing needs ncomping because nothing is in package P"

If your source jar contains packages with non of classes present onto
the server, ncomp will report that each individual class is
NOT_FOUND_IN_SCHEMA yet each packages is ALREADY_NCOMPED:

NOT_FOUND_IN_SCHEMA oracle/aurora/mts/iiop/ORB
NOT_FOUND_IN_SCHEMA oracle/aurora/mts/iiop/SessIiopService
..
ALREADY_NCOMPED oracle/aurora/mts/iiop/

In this particular case the meaning of this ALREADY_NCOMPED is more
like "nothing needs ncomping because nothing is there"

3.4.6  ncomp says NEED_NCOMPING, and then it freezes?

After reporting a series of NEED_NCOMPING, ncomp keeps silent until it
creates the deployment jar and is ready to deploy. Depending on the
machine, this delay can look like a freeze. To see what is going on,
tail file ncomp.log. Another solution is to redirect the output to the
screen with -verbose.

3.4.7  Solaris-specific Settings_*.properties files

On Solaris we ship two platform-specific Settings_*.properties files.
  Settings_solaris.properties
and
  Settings_sunos.properties
File Settings_solaris.properties is picked up by JDKs 1.1.x, file
Settings_sunos.properties is picked up by JDKs 1.2.x and later.

3.4.8  Managing filespace in javavm/admin

The 10.1.0 release of user interface to ncomp does not attempt to
manage the dlls in javavm/admin directory. Because dlls have unique
names, over time there javavm/admin might accumulate a number of
obsolete dlls.

For each given package in a given schema, only the most recently
deployed dll is in use. You can detect which dlls are in use by
analyzing table jaccelerator$dlls or by running the following script:

#!/bin/sh
# list of ncomp dlls in use

usage () {
  echo "libs used by ncomped classes foo/bar*"
  echo "usage: $0 foo/bar"
  exit 1
}

if [ $# -lt 1 ]; then  usage; fi

DIR=`dirname $0`

cat >$DIR/DLLsReport.java <<EOJAVA

package oracle.jaccelerator.utl;
import oracle.aurora.rdbms.Schema;
import oracle.aurora.rdbms.ClassHandle;
import oracle.aurora.rdbms.Handle;
import oracle.aurora.rdbms.ObjectTypeChangedException;
import oracle.sql.CHAR;

import java.io.*;
import java.util.Date;

import java.sql.*;
import oracle.jdbc.driver.*;

public class DLLsReport {
  public static String dll (String schemaAndName) 
    throws SQLException
  {
    int colonIdx = schemaAndName.indexOf(':');
    String name = schemaAndName.substring(colonIdx + 1);
    String schema = schemaAndName.substring(0, colonIdx);
    String  result = "bad handle";

    ClassHandle h = Handle.lookupClass(name, Schema.lookup(schema));
    if (h == null) {
      result = "null handle" + h;
    }
    else {
      result = h.getNcompDllNameAsCHAR().toString();
    }
    return result;
  }
}
EOJAVA

set -x

loadjava -oci8 -resolve -user internal/change_on_install  $DIR/DLLsReport.java

svrmgrl  <<EOI

connect internal/change_on_install

create or replace function isvnc_get_class_dll (pkg varchar2) return VARCHAR2 as
  language java name 'oracle.jaccelerator.utl.DLLsReport.dll(java.lang.String) return java.lang.String';
/
show errors;
select distinct isvnc_get_class_dll(OWNER || ':'  || dbms_java.longname(OBJECT_NAME)) from all_objects where OBJECT_TYPE = 'JAVA CLASS' and dbms_java.longname(OBJECT_NAME) like '$1%' ;

EOI


--  End of README  --
