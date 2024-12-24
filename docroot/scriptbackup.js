
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


class DataPlotter {
    constructor( elementId , title , linecolor ){
        this.m_directionUp = false;
        this.ctx = document.getElementById(elementId).getContext('2d');
        this.m_directionChanged = true;

        const zoomOptions = {
            pan: {
                enabled: true,
                mode: 'y',
                scaleMode: 'y'
            },
            zoom: {
                wheel: {
                    enabled: true,
                },
                pinch: {
                    enabled: true,
                },
                mode: 'x',
                scaleMode: 'y'
            }
        };

        this.m_myLineChart = new Chart(this.ctx, {
                                           type: 'line',
                                           data: {
                                               labels: [],
                                               datasets: [{
                                                       label: '',
                                                       data: [],
                                                       borderColor: linecolor,
                                                       backgroundColor: 'rgb(255, 220, 220)',
                                                       borderWidth: 1,
                                                       pointRadius: 0
                                                   }]
                                           },
                                           options: {
                                               responsive: true,
                                               maintainAspectRatio: false,
                                               animation: {
                                                   duration: 0
                                               },
                                               scales: {
                                                   y: {
                                                       reverse: true,
                                                       beginAtZero: false,
                                                       offset: true,
                                                       display: true,
                                                       title: {
                                                           display: false
                                                       },

                                                       grid: {
                                                           drawOnChartArea: true,
                                                           color: function (context) {
                                                               if (context.tick.index % 25 === 0) {
                                                                   return 'rgba(0 ,0, 0, 1)';
                                                               }
                                                               else if (context.tick.index % 5 === 0) {
                                                                   return 'rgba(50, 50, 50, .75)';
                                                               }
                                                               else if (context.tick.index % 1 === 0) {
                                                                   return 'rgba(100, 100, 100, .25)';
                                                               }
                                                           },
                                                           lineWidth: function (context) {
                                                               if (context.tick.index % 5 === 0) {
                                                                   return 'rgba(0, 0, 0, 1)';
                                                               }
                                                               else if (context.tick.index % 5 === 0) {
                                                                   return 'rgba(50, 50, 50, .75)';
                                                               }
                                                               else if (context.tick.index % 1 === 0) {
                                                                   return 'rgba(0, 0, 0, .25)';
                                                               }
                                                           },
                                                       },

                                                       ticks: {
                                                           autoSkip: false,
                                                           stepSize: 1, // İlk y ekseni için step size
                                                           beginAtZero: true,
                                                           callback: function (value, index) {
                                                               var val = Math.floor(index);
                                                               if( val % 25 === 0 ) {
                                                                   return Math.floor(value);
                                                               }
                                                               else{
                                                                   return '';
                                                               }
                                                           }
                                                       }
                                                   },
                                                   x: {
                                                       type: 'linear',
                                                       position: 'bottom',
                                                       offset: true,
                                                       title: {
                                                           display: false,
                                                       },
                                                       ticks: {
                                                           autoSkip: false,
                                                           stepSize: 1, // İlk y ekseni için step size
                                                           beginAtZero: true,
                                                           callback: function (value, index) {
                                                               var val = Math.floor(index);
                                                               if( val % 1 === 0 ) {
                                                                   return Math.floor(value);
                                                               }
                                                               else{
                                                                   return '';
                                                               }
                                                           }
                                                       },
                                                       grid: {
                                                           drawOnChartArea: true,
                                                           color: function (context) {
                                                               return 'rgba(0 ,0, 0, 1)';

                                                           },
                                                           lineWidth: 1
                                                       },
                                                   }
                                               },
                                               plugins: {
                                                   zoom: zoomOptions,
                                                   title: {
                                                       display: true,
                                                       text: title,
                                                       color:linecolor
                                                   },
                                                   legend: {
                                                       display: false
                                                   },
                                                   tooltip: {
                                                       callbacks: {
                                                           label: function(context) {
                                                               if (!isNaN(context.raw.y)) {
                                                                   return 'Y: ' + context.raw.y.toFixed(1);
                                                               }
                                                               return '';
                                                           }
                                                       }
                                                   }
                                               },
                                               // interaction: {
                                               //     mode: 'nearest',
                                               //     axis: 'y',
                                               //     intersect: false,
                                               //     callbacks: {
                                               //         label: function(context) {
                                               //             return 'Y: ' + context.parsed.y.toFixed(2);
                                               //         }
                                               //     }
                                               // }
                                           }
                                       });

        this.m_myLineChart.options.plugins.zoom.pan.enabled = true;
    }

    chart(){
        return this.m_myLineChart;
    }

    update( depthValue , xValue ){

        if( this.m_myLineChart.data.datasets[0].data[this.m_myLineChart.data.datasets[0].data.length-1] === depthValue ) {
            return;
        }


        let newDataY = this.m_myLineChart.data.datasets[0].data.length === 0 ? 0 : this.m_myLineChart.data.datasets[0].data[this.m_myLineChart.data.datasets[0].data.length - 1] + 1;

        if( this.m_directionUp ) {
            if( this.m_myLineChart.data.datasets[0].data.length > 0 ) {
                if( this.m_myLineChart.data.datasets[0].data[this.m_myLineChart.data.datasets[0].data.length-1] < depthValue ) {
                    this.m_myLineChart.data.datasets[0].data = [];
                    this.m_myLineChart.data.labels = [];
                    this.m_directionUp = false;
                    this.m_directionChanged = true;
                }
            }
        }
        else{
            if( this.m_myLineChart.data.datasets[0].data.length > 0 ) {
                if( this.m_myLineChart.data.datasets[0].data[this.m_myLineChart.data.datasets[0].data.length-1] > depthValue ) {
                    this.m_myLineChart.data.datasets[0].data = [];
                    this.m_myLineChart.data.labels = [];
                    this.m_directionUp = true;
                    this.m_directionChanged = true;
                }
            }
        }



        this.m_myLineChart.data.labels.push( xValue );
        this.m_myLineChart.data.datasets[0].data.push( depthValue );

        while( this.m_myLineChart.data.datasets[0][this.m_myLineChart.data.datasets[0].length-1] - this.m_myLineChart.data.datasets[0][0] > 200 ) {
            this.m_myLineChart.data.datasets[0].shift();
        }

        while( this.m_myLineChart.data.datasets[0].length - this.m_myLineChart.data.labels.length ) {
            this.m_myLineChart.data.labels.shift();
        }

        // // if( this.m_directionChanged ) {
        if( this.m_directionUp ) {
            this.m_myLineChart.options.scales.y.min = newDataY - 31;
            this.m_myLineChart.options.scales.y.max = newDataY + 169;
        }
        else{
            this.m_myLineChart.options.scales.y.min = newDataY - 169;
            this.m_myLineChart.options.scales.y.max = newDataY + 31;
        }
        //     this.m_directionChanged = false;
        // // }





        if( this.m_myLineChart.options.scales.x.min < Math.min(this.m_myLineChart.data.labels) ) {
            this.m_myLineChart.options.scales.x.min = Math.min(this.m_myLineChart.data.labels);
        }

        if( this.m_myLineChart.options.scales.x.max > Math.max(this.m_myLineChart.data.labels) ) {
            this.m_myLineChart.options.scales.x.max = Math.max(this.m_myLineChart.data.labels);
        }
        this.m_myLineChart.update();
    }

}


var project = new Project();
var bridge = new Bridge();
var loggingbridge = new LoggingBridge();



var chainItems;
var chainWidgetId;
var chainParseFunc;

function getChainItems( elementId , func ) {
    chainWidgetId = elementId;
    chainParseFunc = func;

    if( chainItems ) {
        console.log("getChainItems");

        console.log(" CHAINS: " + JSON.stringify(chainItems));

        Wt.emit( elementId , func , chainItems );

    }
    else{
        console.log("chainItems null");

    }


}


function openSocket( websocketUrl , cclElementId , speedElementId, tensionElementId ){

    var projectLastData;

    // Plotter Areas
    var cclPlotter = new DataPlotter('cclContainer',"CCL",'rgba(255, 0, 0, 1)');
    var speedPlotter = new DataPlotter('speedContainer',"Speed",'rgba(0, 0, 255, 1)');
    var tensionPlotter = new DataPlotter('tensionContainer',"Tension",'rgba(255, 150, 0, 1)');
    // var shotDepthPlotter = new ShotDepthPlotter('shotPlotCanvas',"Shot Depth Plot",'rgba(0, 150, 255, 1)');


    let depthDisplayId = document.getElementById( "depthDisplayId" );
    let speedDisplayId = document.getElementById( "speedDisplayId" );
    let tensionDisplayId = document.getElementById( "tensionDisplayId" );


    let projectOpenedWidget = document.getElementById( "projectOpenedWidget" );


    var resetbtn = document.getElementById('cclChartReset');
    if( resetbtn ) {
        var functionBtn = function( chart ) {
            cclPlotter.chart().resetZoom();
        };

        resetbtn.addEventListener('click', functionBtn );
    }

    var ws = new WebSocket(websocketUrl);    // Development Environment


    ws.onopen = function () {
        ws.send("{\"Command\":\"data\"}");

        dispatchEvent(new Event('custom-Event'));
    };


    ws.onmessage = function (evt) {
        var data = JSON.parse(evt.data);
        // console.log(" JSON OBJ: " + JSON.stringify(veri));
        let Sample              = data["Sample_Received"];
        let projectData     = data["Project"];
        let bridgeObj       = data["bridge"];
        let logginngObj     = data["loggingBridge"];

        bridge.update( bridgeObj );
        loggingbridge.update( logginngObj );

        if( projectData ) {
            if( JSON.stringify(projectData) != JSON.stringify(projectLastData) ) {
                projectLastData = projectData;
                Wt.emit( chainWidgetId , chainParseFunc , JSON.stringify(projectData) );
            }
        }


        project.update( projectData );
        project.updateTitleWidget( "projectOpenedWidget" );


        if ( ! Array.isArray( Sample ) ) {
            return;
        }

        var DepthValue;
        var CCLValue;
        var LineSpeedValue;
        var SurfaceTensionValue;
        var ShootingVoltageValue;
        var ShootingCurrentValue;

        Sample.forEach((elementAr) => {

                           elementAr.forEach((element) => {
                                                 if( element.id === "Depth" )           { DepthValue = element.value; }
                                                 if( element.id === "CCL" )             { CCLValue = element.value; }
                                                 if( element.id === "LineSpeed" )       { LineSpeedValue = element.value; }
                                                 if( element.id === "SurfaceTension" )  { SurfaceTensionValue = element.value; }
                                                 if( element.id === "ShootingVoltage" ) { ShootingVoltageValue = element.value; }
                                                 if( element.id === "ShootingCurrent" ) { ShootingCurrentValue = element.value; }
                                             });


                           let DepthBarWidget = document.getElementById( "DepthBarWidget" );
                           let SpeedbarWidget = document.getElementById( "SpeedbarWidget" );
                           let TensionBarWidget = document.getElementById( "TensionBarWidget" );

                           if( DepthValue && LineSpeedValue && SurfaceTensionValue ) {
                               if( DepthBarWidget ) DepthBarWidget.innerText = parseFloat( DepthValue >= 10000 ? parseInt(DepthValue) : DepthValue.toFixed(1) );
                               if( SpeedbarWidget ) SpeedbarWidget.innerText = parseFloat( LineSpeedValue >= 10000 ? LineSpeedValue.toFixed(0) : LineSpeedValue.toFixed(1));
                               if( TensionBarWidget ) TensionBarWidget.innerText = parseFloat( SurfaceTensionValue >= 10000 ? SurfaceTensionValue.toFixed(0) : SurfaceTensionValue.toFixed(1) );

                               if( ! display( depthDisplayId , parseFloat(DepthValue.toFixed(1)) , project.isOpen() ) ) {
                                   depthDisplayId = document.getElementById( "depthDisplayId" );
                               }

                               if( ! display( speedDisplayId , parseFloat(LineSpeedValue.toFixed(1)) , project.isOpen() ) ) {
                                   speedDisplayId = document.getElementById( "speedDisplayId" );
                               }

                               if( ! display( tensionDisplayId , parseFloat(SurfaceTensionValue.toFixed(1)) , project.isOpen() ) ) {
                                   tensionDisplayId = document.getElementById( "tensionDisplayId" );
                               }
                           }

                           cclPlotter.update( DepthValue , CCLValue );
                           speedPlotter.update( DepthValue , LineSpeedValue );
                           tensionPlotter.update( DepthValue , SurfaceTensionValue );
                       });
    };

    ws.onerror = function (evt) {
        console.log("ws onerror = " + evt.data);
    };

    ws.onclose = function () {
        // websocket is closed.
        console.log("Connection closed...");
    };
}

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
