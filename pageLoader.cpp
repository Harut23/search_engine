#include "pageLoader.hpp"
#define CURL_STATICLIB
#include<iostream>
#include<list>
#include<string>
#include<vector>
#include <sstream>
#include "Curl/curl.h"
#include "Curl/curlver.h"
#include "Curl/easy.h"
#include "Curl/mprintf.h"
#include "Curl/options.h"
#include "Curl/stdcheaders.h"
#include "Curl/system.h"
#include "Curl/typecheck-gcc.h"
#include "Curl/urlapi.h"
Page PageLoader::load(const std::string& url)
{
    CURLcode request;
    curlpp::Cleanup cleaner;
    request.setOpt(curlpp::Options::Url(url));//harcumy url ova uxarkelu 
    std::list<std::string> headers = { "Accept: text/html" };//ete cody pdfa ekel 
    request.setOpt(curlpp::Options::HttpHeader(headers));
    request.setOpt(curlpp::Options::FollowLocation(true));
    std::ostringstream os;
    curlpp::options::WriteStream ws(&os);
    request.setOpt(ws);
    request.perform();
    std::string effUrl;
    curlpp::infos::EffectiveUrl::get(request, effUrl);
    auto type = curlpp::infos::ContentType::get(request);
    if (type.find("text/html") == std::string::npos) {
        return Page(effUrl, "", 505);
    }
    return Page(effUrl, os.str(), curlpp::infos::ResponseCode::get(request));
}





















/*#define CURL_STATICLIB
#include "pageLoader.hpp"

#include "curl/curl.h"
#include "curl/curlver.h"
#include "curl/easy.h"
#include "curl/mprintf.h"
#include "curl/multi.h"
#include "curl/options.h"
#include "curl/stdcheaders.h"
#include "curl/system.h"
#include "curl/typecheck-gcc.h"
#include "curl/urlapi.h"
#include <sstream>


#include "curlpp/curlpp.h"
#include <string>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>
#define CURL_STATICLIB


#include "pageLoader.hpp"
#include "curl/curl.h"
#include <string>
#include <sstream>
#include <list>
#include "curl/cURL.h"
#include "curl/Easy.h"
#include "curl/Options.h"
#include "curl/Infos.h"

Page PageLoader::load(const std::string &url)
{
    
        CURLcode request;//harcman patasxany pahelu enq sra mej,heto iranic vercnelu enq mer uzacnery
     
        curl_easy_cleanup (*cleaner)  ; // destructori pes bana,,,inch anumes maqruma

        request.setOpt(curl::Options::Url(url));//harcumy url ova uxarkelu

        std::list<std::string> headers = { "Accept: text/html" };//ete cody or,pdf a ekel...

        request.setOpt(curl::Options::HttpHeader(headers));//ete texty html chi mez petq chi

        request.setOpt(curl::Options::FollowLocation(true));//ete gna bayc tesni vor karelia texapoxvel urish link tox gna gtni

        std::ostringstream os;//stringeri het ashxatox string a vor requestery lcnenq mejy
        curl::options::WriteStream ws(&os);

        request.setOpt(ws);

        request.perform();

        std::string effUrl;
        curl::infos::EffectiveUrl::get(request, effUrl);//requestic url y vercnum qcum a effUrl i mej

        auto type = curl::infos::ContentType::get(request);
        if (type.find("text/html") == std::string::npos) {//nayum enq text html ka te che ete kod chka =>et kayqy el mez petq chi -> 404
            return Page(effUrl, "", 682);
        }
        return Page(effUrl, os.str()  /*24 tox  , curlpp::infos::ResponseCode::get(request));
}//sarqum enq page u veradarcnum enq
    



*/

















