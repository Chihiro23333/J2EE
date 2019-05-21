function draw(){
    var canvas = document.getElementById("draw-in-me");
    if(canvas.getContext){
        var ctx = canvas.getContext("2d");
        ctx.beginPath();
        ctx.moveTo(120.0,32.0);
        ctx.lineTo(8.0, 40.0);
        ctx.lineTo(60.0, 0);
        ctx.closePath();
        ctx.fill();
        ctx.lineWidth = 2.0;
        ctx.strokeStyle = "rgb(255, 255, 255)";
        ctx.stroke();
    }
}

window.onload = draw;