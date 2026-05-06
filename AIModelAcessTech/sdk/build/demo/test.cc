#include "../../include/ChatSDK.h"
#include "../../include/common.h"
#include "../../include/util/myLog.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <spdlog/common.h>
using namespace std;

int main()
{
    bite::Logger::initLogger("test", "stdout",spdlog::level::level_enum::info);
    shared_ptr<ai_chat_sdk::APIConfig> deepseek = std::make_shared<ai_chat_sdk::APIConfig>();
    deepseek->_modelName = "deepseek-chat";
    deepseek->_maxTokens = 2048;
    deepseek->_temperature = 0.7;
    char* deepseek_api_key = getenv("DEEPSEEK_API");
    if(deepseek_api_key==nullptr)
    {
        cout << "deep_seek_api_key is null" << endl;
        return -1;
    }
    else {
        cout << deepseek_api_key << endl;
    }
    deepseek->_apiKey = deepseek_api_key;
    shared_ptr<ai_chat_sdk::ChatSDK> chat_sdk = std::make_shared<ai_chat_sdk::ChatSDK>();
    vector<shared_ptr<ai_chat_sdk::Config>> configs;
    configs.push_back(deepseek);
    chat_sdk->initModels(configs);
    auto models = chat_sdk->getAvailableModels();
    cout << "available models:" << endl;
    for(auto &m: models)
    {
        cout << m._modelName << endl;
    }
    string session = chat_sdk->createSession("deepseek-chat");
    while(true)
    {
        string message;
        cin >> message;
        chat_sdk->sendMessageStream(session, message, [](const string& response, bool end){
            cout << "ai回应: " << response << endl;
            if(end == true)
            {
                cout << "消息接收完成" << endl;
            }

        });
    }
    return 0;
}