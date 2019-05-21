

function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}

addLoadEvent(appendChildComplex);

function createNode(){
    var ele = document.createElement("p");
    var str = "nodename=";
    str += ele.nodeName;
    str += ";nodetype=";
    str += ele.nodeType;
    alert(str);
}

function appendElement(){
    var p = document.createElement("p");
    var p_text = document.createTextNode("hello JavaScript");
    p.appendChild(p_text);
    var  testdiv = document.getElementById("testdiv");
    testdiv.appendChild(p);
}

function appendChildComplex(){
    var p = document.createElement("p");
    var txt1 = document.createTextNode("This is");

    var em = document.createElement("em");
    var txt2 = document.createTextNode("my");

    var txt3 = document.createTextNode("content.");

    var testdiv = document.getElementById("testdiv");

    p.appendChild(txt1);
    em.append(txt2);
    p.appendChild(em);
    p.appendChild(txt3);
    testdiv.appendChild(p);
}
