
class Bridge {
    constructor() {
        this.m_isDauConnected = false;
    }

    isDauConnected() {
        return this.m_isDauConnected;
    }

    update( bridgeObj ) {

        if( bridgeObj.hasOwnProperty ( "isDauConnected" ) ) {
            this.m_isDauConnected = bridgeObj["isDauConnected"];
        }
        else{
            this.m_isDauConnected = false;
        }

        var wlConnectedIconId = document.getElementById( "wlConnectedIconId" );
        var wlConnectedTextId = document.getElementById( "wlConnectedTextId" );

        if( wlConnectedIconId ) {
            if( this.m_isDauConnected ) {
                wlConnectedIconId.style.backgroundImage = "url('images/statebutton-green.svg')";
                if( wlConnectedTextId ) {
                    wlConnectedTextId.innerText = "WLControl Connected";
                }
            }
            else{
                wlConnectedIconId.style.backgroundImage = "url('images/statebutton-black.svg')";
                if( wlConnectedTextId ) {
                    wlConnectedTextId.innerText = "WLControl Disconnected";
                }
            }
        }
        else{
            console.log("can not get Element");
        }
    }
}

class LoggingBridge {
    constructor() {
        this.m_isDauConnected = false;
    }

    isDauConnected() {
        return this.m_isDauConnected;
    }

    update( loggingObj ) {

        if( loggingObj.hasOwnProperty ( "isDauConnected" ) ) {
            this.m_isDauConnected = loggingObj["isDauConnected"];
        }
        else{
            this.m_isDauConnected = false;
        }

        var loggingConnectedIconId = document.getElementById( "loggingConnectedIconId" );
        var loggingConnectedTextId = document.getElementById( "loggingConnectedTextId" );

        if( loggingConnectedIconId ) {
            if( this.m_isDauConnected ) {
                loggingConnectedIconId.style.backgroundImage = "url('images/statebutton-green.svg')";
                if( loggingConnectedTextId ) {
                    loggingConnectedTextId.innerText = "Logging Connected";
                }
            }
            else{
                loggingConnectedIconId.style.backgroundImage = "url('images/statebutton-black.svg')";
                if( loggingConnectedTextId ) {
                    loggingConnectedTextId.innerText = "Logging Disconnected";
                }
            }
        }
        else{
            console.log("can not get Element");
        }
    }
}

class Project {

    constructor() {
        this.m_isOpen = false;
        this.m_titleWidget = null;
    }

    isOpen() {
        return this.m_isOpen;
    }

    clientName() {
        return this.m_clientName;
    }

    wellName() {
        return this.m_wellName;
    }

    stage() {
        return this.m_stage;
    }

    color() {
        return this.m_color;
    }

    run() {
        return this.m_run;
    }

    pad() {
        return this.m_pad;
    }

    update( projectObj ) {
        this.m_isOpen = projectObj["isOpen"];
        this.m_clientName = projectObj["clientName"];
        this.m_wellName = projectObj["wellName"];
        this.m_stage = projectObj["stage"];
        this.m_pad = projectObj["pad"];
        this.m_run = projectObj["run"];
        this.m_color = projectObj["color"];
    }

    updateTitleWidget( widgetid ) {
        if( ! this.m_titleWidget ){
            this.m_titleWidget = document.getElementById( "projectOpenedWidget" );
        }

        if( ! this.m_titleWidget ) {
            return;
        }

        if( this.m_isOpen ) {
            this.m_titleWidget.style.backgroundColor = this.color();

            var projectTitleText = this.clientName() + "/" +
            this.pad() + "/" +
            this.wellName() + "/" +
            this.stage() + "/" +
            this.run();

            if( this.m_titleWidget.innerText !== projectTitleText ) {
                this.m_titleWidget.innerText = projectTitleText;
            }
        }
        else{
            this.m_titleWidget.style.backgroundColor = "gray";
            this.m_titleWidget.innerText = "No Project Opened";
        }

    }
}



// var project = new Project();
// var bridge = new Bridge();
// var loggingbridge = new LoggingBridge();


var webSocket;
var wsConnected = false;
var m_webSocketUrl;

// var chainItems;
// var chainWidgetId; // Chain TableView
// var chainParseFunc;
var jobInfo;
var jobInfoRequested = false;
var jobInfoElementId;
var jonInfoParseFunc;

// function getChainItems( elementId , func ) {
//     chainWidgetId = elementId;
//     chainParseFunc = func;

//     if( chainItems ) {
//         Wt.emit( elementId , func , chainItems );
//     }
// }



function getJobInfo( elementId , func ){

    jonInfoParseFunc = func;
    jobInfoElementId = elementId;

    var obj = {"req":"project"};

    if( webSocket ) {
        if( wsConnected ) {
            console.log("JobRequest Sended");
            jobInfoRequested = true;
            webSocket.send(JSON.stringify(obj));
        }
    }


}


// function openSocket( websocketUrl , dauUuid , projectUuid , cclElementId , speedElementId, tensionElementId ){

//     m_webSocketUrl = websocketUrl;


//     var projectLastData;
//     var depthDisplayId;
//     var tensionDisplayId;
//     var speedDisplayId;

//     var ws = new WebSocket(m_webSocketUrl);    // Development Environment


//     ws.onopen = function () {
//         console.log("onOpen");

//         const jsonData = {
//             uuid: dauUuid,
//             projectUuid: projectUuid
//         };

//         ws.send(JSON.stringify(jsonData));
//         wsConnected = true;
//         webSocket = ws;
//     };


//     ws.onmessage = function (evt) {
//         var data = JSON.parse(evt.data);
//         let Sample          = data["Sample_Received"];
//         let projectData     = data["Project"];
//         let bridgeObj       = data["bridge"];
//         let logginngObj     = data["loggingBridge"];

//         let jobInfoObj     =  data["jobInfo"];

//         if( jobInfoRequested ) {
//             if( jobInfoObj ) {
//                 jobInfoRequested = false;
//                 Wt.emit( jobInfoElementId , jonInfoParseFunc , JSON.stringify(jobInfoObj) );
//             }
//         }




//         if( bridgeObj ) {
//             bridge.update( bridgeObj );
//         }

//         if( logginngObj ) {
//             loggingbridge.update( logginngObj );
//         }


//         if( projectData ) {
//             if( JSON.stringify(projectData) != JSON.stringify(projectLastData) ) {
//                 projectLastData = projectData;
//                 Wt.emit( chainWidgetId , chainParseFunc , JSON.stringify(projectData) );
//             }
//             project.update( projectData );
//             project.updateTitleWidget( "projectOpenedWidget" );

//         }




//         if ( ! Array.isArray( Sample ) ) {
//             return;
//         }

//         var DepthValue;
//         var CCLValue;
//         var LineSpeedValue;
//         var SurfaceTensionValue;
//         var ShootingVoltageValue;
//         var ShootingCurrentValue;

//         Sample.forEach((elementAr) => {

//                            elementAr.forEach((element) => {
//                                                  if( element.id === "Depth" )           { DepthValue = element.value; }
//                                                  if( element.id === "CCL" )             { CCLValue = element.value; }
//                                                  if( element.id === "LineSpeed" )       { LineSpeedValue = element.value; }
//                                                  if( element.id === "SurfaceTension" )  { SurfaceTensionValue = element.value; }
//                                                  if( element.id === "ShootingVoltage" ) { ShootingVoltageValue = element.value; }
//                                                  if( element.id === "ShootingCurrent" ) { ShootingCurrentValue = element.value; }
//                                              });



//                            // let DepthBarWidget = document.getElementById( "DepthBarWidget" );
//                            // let SpeedbarWidget = document.getElementById( "SpeedbarWidget" );
//                            // let TensionBarWidget = document.getElementById( "TensionBarWidget" );

//                            // if( DepthValue && LineSpeedValue && SurfaceTensionValue ) {
//                            //     if( DepthBarWidget ) DepthBarWidget.innerText = parseFloat( DepthValue >= 10000 ? parseInt(DepthValue) : DepthValue.toFixed(1) );
//                            //     if( SpeedbarWidget ) SpeedbarWidget.innerText = parseFloat( LineSpeedValue >= 10000 ? LineSpeedValue.toFixed(0) : LineSpeedValue.toFixed(1));
//                            //     if( TensionBarWidget ) TensionBarWidget.innerText = parseFloat( SurfaceTensionValue >= 10000 ? SurfaceTensionValue.toFixed(0) : SurfaceTensionValue.toFixed(1) );

//                            //     if( ! display( depthDisplayId , parseFloat(DepthValue.toFixed(1)) , project.isOpen() ) ) {
//                            //         depthDisplayId = document.getElementById( "depthDisplayId" );
//                            //     }

//                            //     if( ! display( speedDisplayId , parseFloat(LineSpeedValue.toFixed(1)) , project.isOpen() ) ) {
//                            //         speedDisplayId = document.getElementById( "speedDisplayId" );
//                            //     }

//                            //     if( ! display( tensionDisplayId , parseFloat(SurfaceTensionValue.toFixed(1)) , project.isOpen() ) ) {
//                            //         tensionDisplayId = document.getElementById( "tensionDisplayId" );
//                            //     }
//                            // }
//                        });
//     };

//     ws.onerror = function (evt) {
//         console.log("ws onerror = " + evt.data);
//         wsConnected = false;
//     };

//     ws.onclose = function () {
//         // websocket is closed.
//         wsConnected = false;
//         console.log("webSocket Connection closed...");
//     };
// }

function display( displayId , value , projectOpened ){

    if( displayId ) {
        displayId.innerText = value;

        if( projectOpened ) {
            displayId.style.backgroundColor = "red";
        }
        else{
            displayId.style.backgroundColor = "gray";
        }
        displayId.style.fontSize = "5vw";
        return true;
    }else{
        return false;
    }
}






function setConnectionLost( connectionStatus ) {

    if( ! connectionStatus ) {
        const rootElement = document.getElementById("root");

        let warnDiv = document.createElement("div");
        warnDiv.id = "ConnectonLostWidget";

        warnDiv.style.color = "white";
        warnDiv.style.backgroundColor = "rgba(50,50,50,0.90)";
        warnDiv.style.position = 'fixed';
        warnDiv.style.width = "100%";
        warnDiv.style.height = "100%";
        warnDiv.style.top = "0px";
        warnDiv.style.left = "0px";
        warnDiv.style.zIndex = "1111";

        let node = document.createElement("div");
        node.innerHTML = "<h1>Loading ...</h1>";
        node.style.position = 'absolute';
        node.style.top = "45%";
        node.style.left = "37%";

        warnDiv.appendChild(node);
        rootElement.appendChild(warnDiv);
    }
    else {
        const rootElement = document.getElementById("root");
        let warnDiv = document.getElementById("ConnectonLostWidget");

        if( warnDiv ) {
            warnDiv.remove();
        }
    }
}


var connectionCountSocket = null;
var connectionCount = 0;
function checkConnections( elementid , func , webSocketUrl) {

    console.log("Function: " + elementid + " " + func );



    if( connectionCountSocket == null ) {
        connectionCountSocket = new WebSocket( webSocketUrl );
    }else{
        Wt.emit( elementid , func , parseInt( connectionCount ) );
        return;
    }

    connectionCountSocket.onopen = function () {
        connectionCountSocket.send("{\"Command\":\"command\"}");
        console.log("Connected Conecction Count");
    };

    connectionCountSocket.onmessage = function (evt) {
        var veri = JSON.parse(evt.data);
        connectionCount = parseInt( veri["Connection"] );
        console.log( "Connection Count: " + connectionCount + " -- " + veri["Connection"]);
        Wt.emit( elementid , func , parseInt( connectionCount ) );
    };

    connectionCountSocket.onerror = function (evt) {
        console.log("ws onerror = " + evt.data);
    };

    connectionCountSocket.onclose = function () {
        // websocket is closed.
        console.log("Connection closed...");
    };


}
