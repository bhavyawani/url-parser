#include <iostream>
#include <string.h>
using namespace std;

int main()
{

  string url, protocol, url_new, host, port, path;
  size_t found = 0, found1 = 0;

  protocol = "Absent";
  port = "Absent";
  path = "Absent";

  cout<<"\nEnter url:";
  getline (cin, url);

  found = url.find_first_of(":");

  if(!(found == -1) && (url.at(found+1) == '/')) 
  {
    protocol = url.substr(0,found);
    url = url.substr(found+3);
  }

  found = url.find_first_of(":");

  if( !(found == -1) && ((url.at(found+1) == '0') || (url.at(found+1) == '1') || (url.at(found+1) == '2') || (url.at(found+1) == '3') || (url.at(found+1) == '4') || (url.at(found+1) == '5') || (url.at(found+1) == '6') || (url.at(found+1) == '7') || (url.at(found+1) == '8') || (url.at(found+1) == '9')))
  {
      host = url.substr(0,found);
      url_new = url.substr(found+1);
      found1 = url_new.find_first_of("/");

      if(!(found1 == -1))
      {
        port = url_new.substr(0,found1);
        path = url_new.substr(found1+1);
      }
      else
        port = url_new;
  }
  else if (!(url.find_first_of("/") == -1)) 
  {
    found = url.find_first_of("/");
    host = url.substr(0,found);
    path = url.substr(found+1);
  }
  else
  {
    host = url;
  }
  
  cout<<"\nProtocol: "<<protocol;  //Optional
  cout<<"\nDomain(host): "<<host;   
  cout<<"\nPort: "<<port;    //Optional
  cout<<"\nPath: "<<path;    //Optional
  return 0;   
}
  
