///USING NAMESPACE IN JAVASCRIPT
///https://www.geeksforgeeks.org/javascript-namespace/

var projectLastData;

var project = new Project();
var bridge = new Bridge();
var loggingbridge = new LoggingBridge();

function startPlotter( dauuuid , projectuuid , websocket , cclContainer , speedContainer , tensionContainer ){

    var ws = new WebSocket( websocket );



    ws.onopen = function() {
        const jsonData = {
            // uuid: "f6028973-2169-4597-ba9b-5289f19d5f47"
            uuid: dauuuid,
            projectUuid: projectuuid
        };
        ws.send(JSON.stringify(jsonData));
    };


    ws.onmessage = function (evt) {

        var data = JSON.parse( evt.data );
        let sample = data["Sample_Received"];
        let projectData     = data["Project"];
        let bridgeObj       = data["bridge"];
        let logginngObj     = data["loggingBridge"];
        let chainItemsState     = data["chainItems"];

        let pAnnos = data["pAnnos"];

        if( cclContainer )
            cclContainer.plotter.processData( sample , pAnnos  );

        if( speedContainer )
            speedContainer.plotter.processData( sample , pAnnos  );

        if( tensionContainer )
            tensionContainer.plotter.processData( sample , pAnnos );

        updateDisplayToolBar( sample );
        updateProjectData( projectData );
        bridge.update( bridgeObj );
        loggingbridge.update( logginngObj );
        chainItemsStateUpdate( chainItemsState );

    }

    ws.onerror = function (evt) {
        console.log("ws onerror = " + evt.data);
    };

    ws.onclose = function () {
        // websocket is closed.
        console.log("webSocket Connection closed...");
    };
}

function updateDisplayToolBar( Sample ) {
    if( ! Sample ) {
        return;
    }

    Sample.forEach((elementAr) => {

                       elementAr.forEach((element) => {
                                             if( element.id === "Depth" )           { DepthValue = element.value; }
                                             if( element.id === "CCL" )             { CCLValue = element.value; }
                                             if( element.id === "LineSpeed" )       { LineSpeedValue = element.value; }
                                             if( element.id === "SurfaceTension" )  { SurfaceTensionValue = element.value; }
                                             if( element.id === "ShootingVoltage" ) { ShootingVoltageValue = element.value; }
                                             if( element.id === "ShootingCurrent" ) { ShootingCurrentValue = element.value; }
                                         });




                       var depthDisplayBar = document.getElementById( "DepthBarWidget" );
                       if( depthDisplayBar ) {
                           depthDisplayBar.innerText = parseFloat(DepthValue.toFixed(1));
                       }

                       var speedDisplayBar = document.getElementById( "SpeedbarWidget" );
                       if( speedDisplayBar ) {
                           speedDisplayBar.innerText = parseFloat(LineSpeedValue.toFixed(1));
                       }

                       var tensionDisplayBar = document.getElementById( "TensionBarWidget" );
                       if( tensionDisplayBar ) {
                           tensionDisplayBar.innerText = parseFloat(SurfaceTensionValue.toFixed(1));
                       }

                   });
}





var chainItems;     // Chain TableView ContainerId
var chainWidgetId;  // Chain TableView
var chainParseFunc; // Chain json Parse Function
var chainItemsLatestState; // latest chainItemsState)

function chainItemsStateUpdate( chainsItemState ) {
    if( JSON.stringify(chainItemsLatestState) != JSON.stringify(chainsItemState) ) {
        chainItemsLatestState = chainsItemState;
        if( chainWidgetId ) {
            Wt.emit( chainWidgetId , chainParseFunc , JSON.stringify(chainItemsLatestState) );
        }

    }
}

function updateProjectData( projectData ) {

    // if( JSON.stringify(projectData) != JSON.stringify(projectLastData) ) {
        // projectLastData = projectData;
        // if( chainWidgetId ) {
        //     Wt.emit( chainWidgetId , chainParseFunc , JSON.stringify(projectData) );
        // }

    // }
    project.update( projectData );
    project.updateTitleWidget( "projectOpenedWidget" );

}





function getChainItems( elementId , func ) {
    chainWidgetId = elementId;
    chainParseFunc = func;

    if( chainItems ) {
        Wt.emit( elementId , func , chainItems );
    }
}

function myFunction() {
  var x = document.getElementById("myTopnav");
  if (x.className === "topnav") {
    x.className += " responsive";
  } else {
    x.className = "topnav";
  }
}


function timeout( obj  , element ){


    console.log("timout");

    obj[0][0] = Math.random() * 400;

    console.log( "Obj: " + obj );


    Wt.emit(element, 'dosome');

    setTimeout(function() { timeout(obj) }, 2000);

    // var o = objRef.wtObj;
    // if( o ) {
    //     console.log("Updated");
    //     o.repaint();
    // }else{
    //             console.log("NOT Updated");

    // }
    // .repaint();
}
