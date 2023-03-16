g++ -c main.cpp
g++ -o main main.o -lboost_system -lboost_thread -lboost_timer -pthread -lsfml-graphics -lsfml-window -lsfml-system 
g++ -c chat_client.cpp
g++ -o chat_client chat_client.o -lboost_system -lboost_timer -lboost_thread -pthread