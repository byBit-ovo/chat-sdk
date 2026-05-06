test: test.cc
	g++ $^ -o $@ -L../ -lai_chat_sdk -L/usr/lib/x86_64-linux-gnu/ -lsqlite3 -ljsoncpp \
	-lcrypto -lssl -lcurl -lspdlog -lfmt -lpthread -g

.PHONY:clean
clean:
	rm -fr test