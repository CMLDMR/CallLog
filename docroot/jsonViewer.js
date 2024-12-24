function syntaxHighlight(json) {

    console.log( json );
    var j = JSON.stringify( json );
    j = j.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');

    console.log( "replace1: " + j );

    var j2 = j.replace(/("(\\u[a-zA-Z0-9]{4}|\\[^u]|[^\\"])*"(\s*:)?|\b(true|false|null)\b|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?)/g, function (match) {
        var cls = 'number';
        if (/^"/.test(match)) {
            if (/:$/.test(match)) {
                cls = 'key';
            } else {
                cls = 'string';
            }
        } else if (/true|false/.test(match)) {
            cls = 'boolean';
        } else if (/null/.test(match)) {
            cls = 'null';
        }
        return '<span class="' + cls + '">' + match + '</span>';
    });

    console.log( "replace2: " + j2 );

                     /("(\\u[a-zA-Z0-9]{4}|\\[^u]|[^\\"])*"(\s*:)?|\b(true|false|null)\b|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?)/g
    return j.replace(/("(\\u[a-zA-Z0-9]{4}|\\[^u]|[^\\"])*"(\s*:)?|\b(true|false|null)\b|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?)/g, function (match) {
        var cls = 'number';
        if (/^"/.test(match)) {
            if (/:$/.test(match)) {
                cls = 'key';
            } else {
                cls = 'string';
            }
        } else if (/true|false/.test(match)) {
            cls = 'boolean';
        } else if (/null/.test(match)) {
            cls = 'null';
        }
        return '<span class="' + cls + '">' + match + '</span>';
    });
}

function jsonViewer( element , json ) {

    // var obj = {a:1, 'b':'foo', c:[false,'false',null, 'null', {d:{e:1.3e5,f:'1.3e5'}}]};
    // var str = JSON.stringify(obj, undefined, 4);

   // var str = JSON.stringify(json, undefined, 4);
    // element.innerHTML = syntaxHighlight( str );

    // document.body.appendChild(document.createElement('pre')).innerHTML = inp;

    var newElement = document.createElement('pre');

    var s = logJsonDetailed( newElement , json , 4 );

    if( ! s ) {
        console.log("Undefined Element");
        return;
    }

    console.log( "Element: " + s );

    var node = document.createElement("div");
    // node.appendChild( s );
    element.appendChild( node );
}


function logJsonDetailed( data, indent = 0) {
    const indentation = ' '.repeat(indent); // Girinti için boşluk ekle

    if (Array.isArray(data)) {
        // Eğer veri bir dizi ise
        const newElement = document.createElement("span");
        newElement.className = cls;
        newElement.innerHTML = "Array";

        data.forEach((item, index) => {
             var cls;
             if( typeof value == "string" ) {
                 cls = "string";
             }else if( typeof value == "boolean" ) {
                 cls = "boolean";
             }else if( typeof value == "number" ) {
                 cls = "number";
             }


             var rElement = logJsonDetailed( item , indent ); // Dizi elemanlarını işle
             newElement.appendChild( rElement );


        });

        return newElement;

    } else if (typeof data === 'object' && data !== null) {
        // Eğer veri bir nesne ise

        for (const [key, value] of Object.entries(data)) {

            if (typeof value === 'object' && value !== null) {
                console.log(`${indentation}${key}: (type: ${typeof value})`);

                var cls = "object";
                const newElement = document.createElement("span");
                newElement.innerHTML = key+":"+value;
                newElement.className = object;

                var rElement = logJsonDetailed( newElement , value , indent + 4); // Daha derine in
                newElement.appendChild( rElement );
                return newElement;
            } else {
                console.log(`${indentation}${key}: ${value} (type: ${typeof value})`);

                var cls;
                if( typeof value == "string" ) {
                    cls = "string";
                }else if( typeof value == "boolean" ) {
                    cls = "boolean";
                }else if( typeof value == "number" ) {
                    cls = "number";
                }
                const newElement = document.createElement("div");
                newElement.innerHTML = key + ":" + value;
                newElement.className = cls;

                return newElement;
            }


        }
    } else {
        // Eğer veri basit bir tür ise (string, number, boolean, vb.)
        console.log(`${indentation}${data} (type: ${typeof value})`);

        var cls;
        if( typeof data == "string" ) {
            cls = "string";
        }else if( typeof data == "boolean" ) {
            cls = "boolean";
        }else if( typeof data == "number" ) {
            cls = "number";
        }

        const newElement = document.createElement("span");
        newElement.innerHTML = data;
        newElement.className = cls;
        return newElement;

    }

    console.log("-----");
    // return;
}
