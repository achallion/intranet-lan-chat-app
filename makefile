wlchat:	main.cpp	object/libsnonboost.o	object/libsboost.o
	g++ object/libsnonboost.o object/libsboost.o main.cpp -lboost_system -lboost_thread -lpthread -o wlchat

object/libsnonboost.o:	object/pdress.o	object/user.o	object/crypt.o	object
	ld -r object/pdress.o object/user.o object/crypt.o -o object/libsnonboost.o

object/libsboost.o:	object/connect.o	object/acceptor.o	object/rw.o	object
	ld -r object/connect.o object/acceptor.o object/rw.o -o object/libsboost.o

object/pdress.o:	class/poweraddress/pdress.cpp	object
	g++ -c class/poweraddress/pdress.cpp -o object/pdress.o

object/user.o:	class/user/user.cpp	object
	g++ -c class/user/user.cpp -o object/user.o

object/connect.o:	class/connector/connect.cpp	object
	g++ -c class/connector/connect.cpp -o object/connect.o

object/acceptor.o:	class/acceptor/acceptor.cpp	object
	g++ -c class/acceptor/acceptor.cpp -o object/acceptor.o

object/rw.o:	class/rw/rw.cpp	object
	g++ -c class/rw/rw.cpp -o object/rw.o

object/crypt.o:	class/crypt/crypt.cpp object
	g++ -c class/crypt/crypt.cpp -o object/crypt.o

object:
	mkdir object

clean:
	rm -r object wlchat