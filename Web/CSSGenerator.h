#ifndef CSSGENERATOR_H
#define CSSGENERATOR_H

#include <Wt/WCssStyleSheet.h>
#include <Wt/WApplication.h>
#include <vector>
#include <utility>

namespace CSSGen {

inline std::string createCSS( const std::string &selector , const std::vector< std::pair<std::string,std::string>> &properties ){
    if( ! wApp->styleSheet().isDefined(selector) ) {

        std::string declarations;
        for( const auto &[property , value] : properties ) {
            declarations += property +":"+value+";";
        }
        auto styleSheet = std::make_unique<Wt::WCssTextRule>( "." + selector , declarations );
        Wt::WApplication::instance()->styleSheet().addRule( std::move( styleSheet ) , selector );
    }
    return selector;
}

inline bool createKeyFrame( const std::string &selector , const std::vector< std::pair<std::string,std::string>> &properties ){
    const std::string ruleName =  "@keyframes " + selector;
    if( wApp->styleSheet().isDefined( ruleName ) )
        return false;

    std::string declarations;
    for( const auto &[property , value] : properties ) {
        declarations += property +":"+value+";";
    }

    auto styleSheet = std::make_unique<Wt::WCssTextRule>( ruleName ,declarations );
    Wt::WApplication::instance()->styleSheet().addRule( std::move( styleSheet ) , ruleName );

    return true;
}


inline bool createKeyFrame( const std::string &selector , const std::string &declaration ){
    const std::string ruleName =  "@keyframes " + selector;
    if( wApp->styleSheet().isDefined( ruleName ) )
        return false;

    auto styleSheet = std::make_unique<Wt::WCssTextRule>( ruleName ,declaration );
    Wt::WApplication::instance()->styleSheet().addRule( std::move( styleSheet ) , ruleName );

    return true;
}

}


#endif // CSSGENERATOR_H
