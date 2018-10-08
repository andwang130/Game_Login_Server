#include <iostream>
#include "Net/TcpServer.h"
#include "Net/Tcpcoonetion.h"
#include <assert.h>
#include "commds.h"
#include "protobuf_maegss/User.pb.h"
#include "intermediary.h"
#include "config.h"
using namespace std;
using namespace ZL;
using namespace ZL::Net;
class test
{
public:
    test(Eventloop *loop,inetAddress &address,std::string name):tcpServer(new TcpServer(loop,address,name))
    {
        tcpServer->set_MessageCallback(std::bind(&test::on_meassgcallback,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
        tcpServer->set_ConnectionCallback(std::bind(&test::on_cooncallback,this,std::placeholders::_1));
        tcpServer->set_ThreadInitCallback(std::bind(&test::on_theradinback,this,std::placeholders::_1));
    }
    void start()
    {
        tcpServer->set_threadnumber(4);
        tcpServer->start();
    }

private:
    void on_cooncallback(const TcpcoontionPrt &coon)
    {

    }
    void on_meassgcallback(const TcpcoontionPrt &coon,Buffer*buffer,int m)
    {
        protocol_ aProtocol;
        if(buffer->readableBytes()>=13)
        {   cout<<"收到消息"<<endl;
            int8_t types=buffer->readInt8();
            int32_t len=buffer->readInt32();
            aProtocol.model=buffer->readInt16();
            aProtocol.model2=buffer->readInt16();
            aProtocol.coomd=buffer->readInt32();
            cout<<len<<endl;
            cout<<buffer->readableBytes()<<endl;
            if(buffer->readableBytes()>=len)
            {

                aProtocol.data=buffer->retrieveAsString(len);
                buffer->shrink(0);
                intermeadiary(coon,aProtocol);
            }
        }


    }
    void on_writecallback(const TcpcoontionPrt &coon)
    {
        cout<<coon->get_name()<<endl;

    }
    void on_theradinback(const Eventloop *loop)
    {

    }
    std::shared_ptr<TcpServer> tcpServer;
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    inetAddress address("0.0.0.0",8080);
    Eventloop loop;
    test new_test(&loop,address,"testserver");
    new_test.start();

    return 0;
}