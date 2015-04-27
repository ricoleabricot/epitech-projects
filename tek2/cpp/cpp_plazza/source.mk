## 
## @Author: gicque_p
## @Date:   2015-02-07 00:21:10
## @Last Modified by:   gicque_p
## @Last Modified time: 2015-02-07 00:43:30
##

CLASS_SRC	+=	class/Reception.cpp
CLASS_SRC	+=	class/Kitchen.cpp
CLASS_SRC	+=	class/Cook.cpp
CLASS_SRC	+=	class/Pizza.cpp
CLASS_SRC	+=	class/NamedPipe.cpp
CLASS_SRC	+=	class/PipeData.cpp
CLASS_SRC	+=	class/Process.cpp
CLASS_SRC	+=	class/Thread.cpp
CLASS_SRC	+=	class/Mutex.cpp
CLASS_SRC	+=	class/ScopedLock.cpp
CLASS_SRC	+=	class/CondVar.cpp
CLASS_SRC	+=	class/Parsing.cpp
CLASS_SRC	+=	class/Log.cpp
CLASS_SRC	+=	class/Misc.cpp
CLASS_SRC	+=	class/Error.cpp

TEST_SRC	+=	source/unit.cpp
TEST_SRC	+=	test/Reception.test.cpp
TEST_SRC	+=	test/Parsing.test.cpp
TEST_SRC	+=	test/Log.test.cpp
TEST_SRC	+=	test/Misc.test.cpp
TEST_SRC	+=	$(CLASS_SRC)
