function showPic(whichPic){
    if(!document.getElementById("placeholder"))return false;
    var href = whichPic.getAttribute("href");
    var placeholder = document.getElementById("placeholder");
    placeholder.setAttribute("src",href);

    if(document.getElementById("description")){
        var description  = document.getElementById("description");
        var title = whichPic.getAttribute("title");
        description.firstChild.nodeValue = title;
    }
    return true;
}

function countBodyChildren(){
    var body_element = document.getElementsByTagName("body");
    alert(body_element[0].childNodes.length);
}

// window.onload = countBodyChildren;

addLoadEvent(prepareGllary);
addLoadEvent(createPlaceHolderInsertBeforeGallary);

function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}

function insertAfter(newElement, targetElment){
    var parent = targetElment.parentNode;
    if(parent.lastChild == targetElment){
        parent.appendChild(newElement);
    }else{
        parent.insertBefore(newElement, targetElment.nextSibling);
    }
}

function prepareGllary(){
    if(!document.getElementsByTagName)return false;
    if(!document.getElementById) return false;
    if(!document.getElementById("gllary"))return false;
    var gllary = document.getElementById("gllary");
    var links = gllary.getElementsByTagName("a");
    for(var i = 0; i < links.length; i++){
            links[i].onclick = function(){
                return !showPic(this);
        }
    }
}

function popUp(url){
    window.open(url,"popUp","width=800,height=480");
}

function createPlaceHolder(){
    var img = document.createElement("img");
    img.setAttribute("src","images/1.png");
    img.setAttribute("id","placeholder");

    var pNode = document.createElement("p");
    pNode.setAttribute("id","description");
    var txt1 = document.createTextNode("Choose a image");
    pNode.appendChild(txt1);


    document.body.appendChild(img);
    document.body.appendChild(pNode);
    // var body = document.getElementsByTagName("body")[0];
    // body.appendChild(img);
    // body.appendChild(pNode);
}

function createPlaceHolderInsertBeforeGallary(){
    var img = document.createElement("img");
    img.setAttribute("src","images/1.png");
    img.setAttribute("id","placeholder");

    var pNode = document.createElement("p");
    pNode.setAttribute("id","description");
    var txt1 = document.createTextNode("Choose a image");
    pNode.appendChild(txt1);


    var gllary = document.getElementById("gllary");
    gllary.parentNode.insertBefore(img,gllary);
    gllary.parentNode.insertBefore(pNode,gllary);
}

