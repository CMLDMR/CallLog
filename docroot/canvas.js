
class Graph {
    constructor(config) {

        this.m_config = config;




        this.m_parent = document.getElementById(this.m_config.id);


        this.m_content = document.createElement("div");
        this.m_content.id = this.m_config.id + "canvasContent";
        this.m_content.style.position = "relative";

        this.m_content.style.width = "100%";
        this.m_content.style.height = "600px";
        this.m_content.style.margin = "auto";

        this.m_parent.appendChild(this.m_content);

        this.m_canvas = document.createElement('canvas');
        this.m_canvas.style.position = "absolute";

        this.m_content.appendChild(this.m_canvas);
        this.m_ctx = this.m_canvas.getContext('2d');

        this.leftPad = config.leftPadding;


        this.m_yScale = 3.0;


        this.m_xScale = 1.0;
        this.m_xScaleAuto = true;

        this.m_directionDown = true; // down is true


        this.m_pointList = [];
        this.m_pointDataList = [];
        this.m_minPointY = 0;
        this.m_RangeY = 150; // 150 fit visible
        this.m_offsetY = 0;
        this.m_gridOffsetY = 0;

        this.isDraging = false;


        this.minXValue = 99999999;
        this.maxXValue = -99999999;

        this.m_content.addEventListener("mousemove", (event) => {
            if (this.isDraging) {
                this.m_minPointY -= (event.movementY);
                if (this.m_minPointY + this.m_RangeY > this.m_pointDataList.length - 1) {
                    this.m_minPointY = this.m_pointDataList.length - this.m_RangeY - 1;
                }
                if (this.m_minPointY < 0) {
                    this.m_minPointY = 0;
                }

                this.update();
            }
        });

        this.m_canvas.addEventListener("mousedown", (event) => {
            this.isDraging = true;
        });

        this.m_canvas.addEventListener("mouseup", (event) => {
            this.isDraging = false;
        });

        this.m_canvas.addEventListener("mouseout", (event) => {
            this.isDraging = false;
        });

        window.addEventListener("resize", function (event) { this.reSize(event); }.bind(this));

        this.reSize();

    }



    reSize() {
        this.width = this.m_content.getBoundingClientRect().width;
        this.m_canvas.width = this.width;

        this.height = this.m_content.getBoundingClientRect().height;
        this.m_canvas.height = this.height;
        this.m_yScale = this.m_canvas.height / this.m_RangeY;
        this.update();
    }

    addPoint(key, value) {
        const y = value;
        const x = key;
        var exist = false;
        var lastElementY = 0;
        if (this.m_pointDataList.length) {
            var lastElement = this.m_pointDataList[this.m_pointDataList.length - 1];
            if (lastElement) {
                if (lastElement.y == y)
                    exist = true;
            }
        }

        if (exist && this.m_pointDataList.length > 2) {

        } else {
            var lastElement = this.m_pointDataList[this.m_pointDataList.length - 1];
            if (lastElement) {
                if (y > lastElement.y) {
                    if (this.m_directionDown != true) {
                        this.m_pointDataList = [];
                        this.m_directionDown = true;

                        this.minXValue = 99999999;
                        this.maxXValue = -99999999;
                    }
                } else {
                    if (this.m_directionDown != false) {
                        this.m_pointDataList = [];
                        this.m_directionDown = false;

                        this.minXValue = 99999999;
                        this.maxXValue = -99999999;
                    }
                }
            }
            var obj = { "x": x, "y": y };
            this.m_pointDataList.push(obj);

            if (this.m_pointDataList[this.m_pointDataList.length - 1].y > this.m_RangeY) {
                this.m_minPointY++;
            }
            this.update();

        }

    }

    update() {
        this.m_canvas.style.border = this.m_config.style["border"];
        this.m_canvas.style.left = "0px";
        if (this.m_directionDown) { // true = direction to down
            this.drawDownLine();
        } else {
            this.drawUpLine();
        }
        this.updateSettingsValueWidget();
    }


    // Range in ft at y Axis
    pointRange() {
        if (this.m_pointList.length > 1) {
            return this.m_pointList[this.m_pointList.length - 1].y - this.m_pointList[0].y;
        } else {
            return 0;
        }
    }


    // Grid is moving along data
    drawMovingGrid() {

        this.m_ctx.clearRect(0, 0, this.m_canvas.width, this.m_canvas.height);

        if (this.m_pointDataList.length <= 0)
            return;

        this.calculateVisible();


        // Check if XAxis AutoScaled
        if (this.m_xScaleAuto) {
            this.m_xScale = this.m_canvas.width / (this.visibleMaxx() - this.visibleMinx());
        }


        // Draw Grid
        for (const grid of this.m_config.grid) {

            this.m_ctx.beginPath();

            let sh2 = (this.height / grid["divider"]);


            // Vertical Grid
            for (let x = this.leftPad; x < this.width; x += sh2 * this.m_xScale) {
                this.m_ctx.moveTo(x, 0);
                this.m_ctx.lineTo(x, this.height);
            }

            // Horizontal Grid
            for (let j = 0; j <= this.height; j += sh2) {

                let y = (j - ((this.m_minPointY) % (sh2)));

                this.m_ctx.moveTo(this.leftPad, y);
                this.m_ctx.lineTo(this.width, y);

                if (grid.divider === 4) {
                    if (y > 20 && y < this.height - 10) {
                        if (j < this.m_pointList.length)
                            var yFit = this.m_pointList[0];
                        if (yFit) {
                            this.m_ctx.strokeText(parseInt((yFit.y + y) / this.m_yScale) + " ft", 0, y);
                        } else {
                            this.m_ctx.strokeText(parseInt((y) / this.m_yScale) + " ft", 0, y);

                        }
                    }
                }
            }

            this.m_ctx.strokeStyle = grid["color"];
            this.m_ctx.stroke();
        }
    }


    drawDownLine() {
        this.m_ctx.clearRect(0, 0, this.m_canvas.width, this.m_canvas.height);

        if (this.m_pointDataList.length < 2) {
            return;
        }

        if (this.m_xScaleAuto) {
            this.m_xScale = (this.m_canvas.width - this.leftPad) / (this.visibleMaxx() - this.visibleMinx());
        }

        let lastY = 0;
        let lastX = 0;

        this.m_pointList = [];

        var pointList = [];
        for (var i = 0; i < this.m_pointDataList.length; i++) {
            pointList.push(this.m_pointDataList[i]);
        }

        const paddingPercent = 0.85;

        // %15 Padding Down Side
        let difft = Math.abs(pointList[pointList.length - 1].y - pointList[0].y);
        while (difft > this.height / this.m_yScale * paddingPercent) {
            pointList.shift();
            difft = Math.abs(pointList[pointList.length - 1].y - pointList[0].y);
        }

        var diff = this.height * paddingPercent - (pointList[pointList.length - 1].y - pointList[0].y);
        var minY = pointList[0].y;


        for (let i = 1; i < pointList.length; i++) {
            this.m_pointList.push({ x: pointList[i].x, y: pointList[i].y - pointList[0].y });
        }


        // Draw Grid
        for (const grid of this.m_config.grid) {

            let sh2 = (this.height / grid["divider"]);

            // Vertical Grid
            for (let x = this.leftPad; x < this.width; x += sh2) {

                this.m_ctx.beginPath();
                this.m_ctx.moveTo(x, 0);
                this.m_ctx.lineTo(x, this.height);
                this.m_ctx.strokeStyle = grid["color"];
                this.m_ctx.stroke();
            }

            // Horizontal Grid
            for (let j = 0; j <= this.height; j += sh2) {

                this.m_ctx.beginPath();
                this.m_ctx.fillStyle = grid["color"];


                this.m_ctx.moveTo(this.leftPad, j);
                this.m_ctx.lineTo(this.width, j);

                if (grid.divider === 4 && false ) {
                    // if (j < this.m_pointList.length)
                    if (j == 0)
                        this.m_ctx.fillText(parseInt(j + minY) + " ft", 0, j + 10);
                    else
                        this.m_ctx.fillText(parseInt(j + minY) + " ft", 0, j);
                }

                this.m_ctx.strokeStyle = grid["color"];
                this.m_ctx.stroke();
            }
        }


        let drawPoint = [];
        let firstX = this.m_pointList[0].x;
        let firstY = this.m_pointList[0].y;

        for (let i = 1; i < this.m_pointList.length; i++) {

            let x1 = this.m_pointList[i - 1].x;
            let x2 = this.m_pointList[i].x;

            if (this.m_xScaleAuto) {
                // Padding Left and Right Percent %15 = 0.15
                x1 = (x1 - this.visibleMinx()) * this.m_xScale * .7 + this.leftPad + (this.m_canvas.width - this.leftPad) * 0.15;
                x2 = (x2 - this.visibleMinx()) * this.m_xScale * .7 + this.leftPad + (this.m_canvas.width - this.leftPad) * 0.15;
            }

            let y1 = this.m_pointList[i - 1].y - this.m_pointList[0].y;
            let y2 = this.m_pointList[i].y - this.m_pointList[0].y;

            // if min and max value are equal line can not visible
            // check if equal
            if (this.visibleMaxx() == this.visibleMinx()) {
                x1 = (this.width - this.leftPad) / 2 + this.leftPad;
                x2 = (this.width - this.leftPad) / 2 + this.leftPad;
            }

            // Last Point For Label Drawing
            lastY = y2 * this.m_yScale;
            lastX = x2;

            if (i == 1) {
                firstX = x1;
                firstY = y1;
            }

            drawPoint.push({ x: x2, y: y2 });
        }

        if (!drawPoint.length) return;


        // calculate drag delta to fix plot poisiton to fixed point
        diff = this.height * paddingPercent - drawPoint[drawPoint.length - 1].y * this.m_yScale;


        this.m_ctx.beginPath();
        this.m_ctx.lineWidth = 2;
        this.m_ctx.moveTo(firstX, firstY * this.m_yScale);
        for (const obj of drawPoint) {
            this.m_ctx.lineTo(obj.x, (obj.y) * this.m_yScale + diff);
        }
        this.m_ctx.strokeStyle = this.m_config.lineColor;
        this.m_ctx.stroke();
        this.m_ctx.lineWidth = 1;


        if (this.m_pointList.length) {
            this.m_ctx.save();
            this.m_ctx.font = "20px Verdana";
            this.m_ctx.strokeStyle = this.m_config.lineColor;

            this.m_ctx.strokeText("▼", lastX - 10, lastY + 11 + diff);

            this.m_ctx.font = "12px Verdana";

            this.m_ctx.beginPath();
            this.m_ctx.moveTo(this.leftPad, lastY + 12 + + diff);
            this.m_ctx.lineTo(lastX, lastY + 12 + + diff);
            this.m_ctx.stroke();

            const stringFt = (drawPoint[drawPoint.length - 1].y + minY).toFixed(1) + " ft";
            //            const stringFt = ( minY).toFixed(1) + " ft";

            this.m_ctx.fillStyle = "black";
            this.m_ctx.fillRect(0, lastY + 12 + diff,
                this.m_ctx.measureText(stringFt).width + 3, 15);

            this.m_ctx.strokeStyle = "white";

            this.m_ctx.strokeText(stringFt, 0, lastY + 25 + diff);
            this.m_ctx.restore();

            this.m_ctx.strokeStyle = "gray";

            // this.m_ctx.strokeText("Min: " + this.visibleMinx(), this.leftPad + 5, this.height - 10);
            // this.m_ctx.strokeText("Max: " + this.visibleMaxx(), this.width - 50, this.height - 10);
        }
    }


    drawUpLine() {

        this.m_ctx.clearRect(0, 0, this.m_canvas.width, this.m_canvas.height);

        if (this.m_pointDataList.length < 2) {
            return;
        }

        if (this.m_xScaleAuto) {
            this.m_xScale = (this.m_canvas.width - this.leftPad) / (this.visibleMaxx() - this.visibleMinx());
        }

        const paddingFromUpPercent = 0.15;


        this.m_pointList = [];

        var pointList = [];
        for (var i = 0; i < this.m_pointDataList.length; i++) {
            pointList.push(this.m_pointDataList[i]);
        }


        let difft = Math.abs(pointList[pointList.length - 1].y - pointList[0].y);
        while (difft > this.height / this.m_yScale * (1.0 - paddingFromUpPercent)) {
            pointList.shift();
            difft = Math.abs(pointList[pointList.length - 1].y - pointList[0].y);
        }



        for (let i = pointList.length - 1; i >= 0; i--) {
            if (pointList[i]) {
                this.m_pointList.push({ x: pointList[i].x, y: pointList[i].y - pointList[0].y });
            }
        }

        // Draw Grid
        for (const grid of this.m_config.grid) {

            this.m_ctx.beginPath();
            this.m_ctx.fillStyle = grid["color"];

            let sh2 = (this.height / grid["divider"]);

            // Vertical Grid
            for (let x = this.leftPad; x < this.width; x += sh2) {
                this.m_ctx.moveTo(x, 0);
                this.m_ctx.lineTo(x, this.height);
            }

            // Horizontal Grid
            for (let j = 0; j <= this.height; j += sh2) {

                this.m_ctx.moveTo(this.leftPad, j);
                this.m_ctx.lineTo(this.width, j);

                // Labels
                if (grid.divider === 4 && false ) {
                    // if (j < this.m_pointList.length)
                    if (j == 0)
                        this.m_ctx.fillText(parseInt(j + pointList[pointList.length - 1].y) + " ft", 0, j + 10);
                    else
                        this.m_ctx.fillText(parseInt(j + pointList[pointList.length - 1].y) + " ft", 0, j);
                }
            }

            this.m_ctx.strokeStyle = grid["color"];
            this.m_ctx.stroke();
        }




        let drawPoint = [];
        let firstX = 0;
        let firstY = 0;


        for (let i = 0; i < this.m_pointList.length - 1; i++) {

            let x2 = this.m_pointList[i].x;

            if (this.m_xScaleAuto) {
                // Padding Left and Right Percent %15 = 0.15
                x2 = (x2 - this.visibleMinx()) * this.m_xScale * .7 + this.leftPad + (this.m_canvas.width - this.leftPad) * 0.15;
            }

            let y2 = this.m_pointList[i].y - this.m_pointList[0].y + this.height * paddingFromUpPercent;

            // if min and max value are equal line can not visible
            // check if equal
            if (this.visibleMaxx() == this.visibleMinx()) {
                x2 = (this.width - this.leftPad) / 2 + this.leftPad;
            }

            if (i == 0) {
                firstX = x2;
                firstY = y2;
            }

            drawPoint.push({ x: x2, y: y2 });
        }


        if (drawPoint.length <= 0)
            return;


        // calculate drag delta to fix plot poisiton to fixed point
        var diff = this.height * paddingFromUpPercent - drawPoint[0].y * this.m_yScale;


        let lastY = drawPoint[0].y;
        let lastX = drawPoint[0].x;

        this.m_ctx.beginPath();
        this.m_ctx.lineWidth = 2;
        this.m_ctx.moveTo(firstX, firstY * this.m_yScale + diff);
        for (const obj of drawPoint) {
            this.m_ctx.lineTo(obj.x, obj.y * this.m_yScale + diff);
        }
        this.m_ctx.strokeStyle = this.m_config.lineColor;
        this.m_ctx.stroke();
        this.m_ctx.lineWidth = 1;


        // LABELS and Arrow
        if (this.m_pointList.length) {
            this.m_ctx.save();
            this.m_ctx.font = "20px Verdana";
            this.m_ctx.strokeStyle = this.m_config.lineColor;

            this.m_ctx.beginPath();
            this.m_ctx.moveTo(this.leftPad, lastY - 12);
            this.m_ctx.lineTo(lastX + 0, lastY - 12);
            this.m_ctx.stroke();

            this.m_ctx.strokeText("▲", lastX - 10, lastY - 1);

            this.m_ctx.font = "12px Verdana";

            const stringFt = (this.m_pointDataList[this.m_pointDataList.length - 1].y).toFixed(1) + " ft";

            this.m_ctx.fillStyle = "black";
            this.m_ctx.fillRect(0, lastY - 27,
                this.m_ctx.measureText(stringFt).width + 3, 15);
            this.m_ctx.strokeStyle = "white";

            this.m_ctx.strokeText(stringFt , 0, lastY - 15);
            this.m_ctx.strokeStyle = "gray";


            // this.m_ctx.font = "10px Verdana";

            // this.m_ctx.strokeText("Min: " + this.visibleMinx(), this.leftPad + 5, this.height - 10);
            // this.m_ctx.strokeText("Max: " + this.visibleMaxx(), this.width - 70, this.height - 10);
        }

    }


    resetXScale() {
        this.m_xScale = 1;
        this.m_xScaleAuto = false;
        this.update();
    }

    toggleXAutoScale() {
        this.m_xScaleAuto = !this.m_xScaleAuto;
        this.update();
    }


    visibleMinx() {
        var _min = Math.min.apply(Math, this.m_pointList.map(function (event) {
            return parseFloat(event.x);
        }));

        if (this.minXValue > _min) {
            this.minXValue = _min;
        }
        return this.minXValue;
    }

    visibleMaxx() {
        var _max = Math.max.apply(Math, this.m_pointList.map(function (event) {
            return parseFloat(event.x);
        }));

        if (this.maxXValue < _max) {
            this.maxXValue = _max;
        }

        return this.maxXValue;
    }
    /////////////////////////////////////////////////////////////


    updateSettingsValueWidget() {


        var infoContainer = document.getElementById('infodiv');


        // while (infoContainer.hasChildNodes()) {
        //     infoContainer.removeChild(infoContainer.children[0]);
        // }

        function createDiv(elementid) {
            var element = document.getElementById(elementid);
            if (!element) {
                element = document.createElement("div");
                element.id = elementid;
                element.style.width = "100%";
                element.style.height = "15px";
                infoContainer.appendChild(element);
            }
            return element;
        }


        if (infoContainer) {
            infoContainer.style.textAlign = "left";
            infoContainer.style.fontSize = "11px";

            {// Range
                let element = createDiv("rangeid");
                element.innerText = "Range: " + this.m_minPointY + " (" + this.m_RangeY + ") " + (this.m_RangeY + this.m_minPointY) + " < " + this.m_pointDataList.length;
            }
            {// ElementVisibleSize
                let element = createDiv("elementVisibleSizeid");
                element.innerText = "m_pointList.length: " + this.m_pointList.length;
            }
            {// ElementVisibleValueSize
                let element = createDiv("elementVisibleValSizeid");
                element.innerText = "m_pointList.last().y";
                if (this.m_pointList.length > 2)
                    element.innerText = "m_pointList.last().y: " + this.m_pointList[this.m_pointList.length - 1].y;
            }


            {// Available Range
                var element = createDiv("arangeid");

                element.innerText = "Min Max Not";

                if (this.m_pointList.length) {
                    const minft = this.m_pointList[0].y;
                    const maxft = this.m_pointList[this.m_pointList.length - 1].y;
                    element.innerText = "MinValFt: " + minft + " - MaxValFt : " + maxft + " CurrentValFt: " + (maxft - minft);
                }
            }

            {// ElementSize
                let element = createDiv("elementSizeid");
                element.innerText = "m_pointDataList.length: " + this.m_pointDataList.length;
            }

            {// MaxElementValue
                let element = createDiv("elementValueSizeid");
                element.innerText = "m_pointDataList.last().y: 0";

                if (this.m_pointDataList.length > 0)
                    element.innerText = "m_pointDataList.last().y: " + this.m_pointDataList[this.m_pointDataList.length - 1].y;
            }

            {// offset
                let element = createDiv("elementoffsetid");
                element.innerText = "m_offsetY: " + this.m_offsetY;
            }

            {// minPointY
                let element = createDiv("minPOinty");
                element.innerText = "m_minPointY: " + this.m_minPointY;
            }
            {// yScale
                let element = createDiv("yScale");
                element.innerText = "m_yScale: " + this.m_yScale;
            }

        }
    }

}
