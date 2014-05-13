Function.prototype.method = function (name, func) {
    document.writeln('d---------[' + name +']');
    if (!this.prototype[name]) {
        this.prototype[name] = func;
    } else {
	throw {
	    name: "prototyping",
	    message: "trying to redefine an already defined function"
	}
    }
};


Function.method('curry', function (  ) {
    var slice = Array.prototype.slice,
        args = slice.apply(arguments),
        that = this;
    return function (  ) {
        return that.apply(null, args.concat(slice.apply(arguments)));
    };
});

//Function.method('memoize', function (  ) {
//    var memo = []
//        that = this;
//    return function (a) {
//	if (!memo[a]) {
//	    memo[a] = that.apply(a)
//	}
//	return memo[a]
//    };
//});

var memoizer = function (memo, fundamental) {
    var shell = function (n) {
        var result = memo[n];
        if (typeof result !== 'number') {
            result = fundamental(shell, n);
            memo[n] = result;
        }
        return result;
    };
    return shell;
};

var fibo = memoizer([0,1], function(shell,n) { 
    return shell(n-1) + shell(n-2);
});

var factorial = memoizer([1,1], function(shell,n) { 
    return shell(n-1) *n;
});


for (var i = 0; i <= 10; i += 1) {
    document.writeln('// ' + i + ': ' + fibo(i));
}

for (var i = 0; i <= 10; i += 1) {
    document.writeln('// ' + i + ': ' + factorial(i));
}


var testFunc = function(a) {
    if (1) {
	var b = 5;
    }
    document.writeln("In test function " + b);
}


var printAll = function(prefix, o, depth) {
    if (o && depth < 2) {
	for (name in o) {
	    if (typeof o[name] !== 'function') {
		document.writeln(prefix + name + ': ' + o[name] + ' : ' + typeof o[name]);
//		printAll(prefix + '   ', o[name], depth + 1);
	    }
	}
    }
}

document.writeln('Hello, world!');
//printAll('', document,0);

var sum = function (  ) {
    var i, sum = 0;
    for (i = 0; i < arguments.length; i += 1) {
        sum += arguments[i];
    }
    return sum;
};


var add = function(a,b) {
    if (typeof a !== 'number' || typeof b !== 'number')
	throw {
	    name: 'Type error',
	    message: 'add needs numbers'
	    
	    }
      return a + b;

}

var array = [3, 4, 5, 8];
var temp = sum.apply(null, array);    // sum is 7

document.writeln('the sum is ', temp);

String.method('mytrim', function (  ) {
    return this.replace(/^\s+|\s+$/g, '');
});


document.writeln('"' + "   neat   ".mytrim(  ) + '"');

//Number.method('integer', function (  ) {
//    return Math[this < 0 ? 'ceiling' : 'floor'](this);
//});
//
//document.writeln((-10 / 3).integer(  ));  // -3

testFunc(10);


var quo = function (status) {
    return {
        get_status: function (  ) {
            return status;
} };
};
// Make an instance of quo.
var myQuo = quo("amazed");
document.writeln(myQuo.get_status(  ));


var fade = function (node) {
    var level = 1;
    var step = function (  ) {
        var hex = level.toString(16);
        node.style.backgroundColor = '#FFFF' + hex + hex;
        if (level < 15) {
	    level += 1;
            setTimeout(step, 100);
        }
    };
    setTimeout(step, 100);
};

fade(document.body);

document.writeln('done');


