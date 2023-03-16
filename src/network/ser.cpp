#include <fstream>
#include <iostream>
#include <boost/asio.hpp>
#include "schema.pb.h"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read_(tcp::socket & socket) {
       cout << "Inside read_ function \n";
       boost::asio::streambuf buf;
       cout << 0 << endl;
       boost::asio::read_until( socket, buf, "\n" );
       cout << 1 << endl;
       string data = boost::asio::  buffer_cast<const char*>(buf.data());
       cout << 2 << endl;
       return data;
}
void send_(tcp::socket & socket, const string& message) {
       cout << "Inside send_ function \n";
       const string msg = message + "\n";
       boost::asio::write( socket, boost::asio::buffer(message) );
}

int main() {
      
      //Protocol Buffer part
      std::ofstream ofs("binary.data", std::ios_base::out | std::ios_base::binary );
      tutorial::Person* person = new tutorial::Person();
      person->set_name("Hello");
      person->set_id(23);
      person->set_email("person@gmail.com");
      person->SerializeToOstream(&ofs);
      string person_inString = person->SerializeAsString();
      ofs.close();
      
      cout << "here" << endl;
      std::ifstream ifs("binary.data", std::ios_base::in | std::ios_base::binary  );
      cout << "2" << endl;
      tutorial::Person* person2 = new tutorial::Person();
      cout << "3" << endl;
      person2->ParseFromIstream(&ifs);
      cout << "The parsing worked, and id is " << person2->id() << endl;

      tutorial::Person* person3 = new tutorial::Person();
      person3->ParseFromString(person_inString);
      cout << person3->id() << endl;


      //Socket Programming Part
      boost::asio::io_service io_service;
      //listen for new connection
      tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));
      //socket creation 
      tcp::socket socket_(io_service);
      //waiting for connection
      acceptor_.accept(socket_);
      //read operation
      string message = read_(socket_);
      cout << 4 << endl;
      cout << message << endl;
      //write operation
      send_(socket_, person_inString);
      // send_(socket_, person_inString);
      cout << "Servent sent Hello message to Client!" << endl;
   return 0;
}