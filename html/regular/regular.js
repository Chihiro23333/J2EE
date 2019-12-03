
var openFile = function(event) {
    var input = event.target;
    var reader = new FileReader();
    reader.onload = function() {
        if(reader.result) {
           replace(reader.result)
        }
    };
    reader.readAsText(input.files[0]);
};

function replace(testStr){
    var testStr = testStr

    var reg=/<img(?:[^"'>]|"[^"]*"|'[^']*')*>/g
    var srcReg=/src=\"(\S*)\"/
    var array = testStr.match(reg)
    console.log(array)
    var src="";
    array.forEach((value,number,index) =>{
        var src = value.match(srcReg)[1]
        console.log(src)
    })
    src ="newStr123456"
    var replcer = testStr.replace(reg,(replace) =>{
        // console.log(replace)
        return replace.replace(srcReg,(replace) =>{
            return "src=\""+src+"\""
        })
    })
    // console.log(replcer)
}