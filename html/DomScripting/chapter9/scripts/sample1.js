function h1NextSetStyle(){
    var h1list = document.getElementsByTagName('h1');
    for(var i = 0 ; i < h1list.length ; i++){
        var next = getNextElement(h1list[i].nextSibling);
        next.style.fontWeight = "bold";
        next.style.fontSize = "1.2em";
    }
}

function getNextElement(node){
    if(node.nodeType == 1){
        return node;
    }
    if(node.nextSibling){
        return getNextElement(node.nextSibling);
    }
    return null;
}

window.onload = h1NextSetStyle;