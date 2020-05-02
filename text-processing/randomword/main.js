var btn = document.getElementById('btn');
var word_p = document.getElementById('word');

var consonants = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'];
var vowels = ['a','e','i','o','u'];
var alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
var most_common_consonants = ['p','t','k','m','n']
var after_e = ['r', 's', 'n', 'd']

function random(min, max)      { return (min + (Math.random() * (max - min)));            }
function randomChoice(choices) { return choices[Math.round(random(0, choices.length-1))]; }
function inArray(needle, haystack) {
    var length = haystack.length;
    for(var i = 0; i < length; i++) {
        if(haystack[i] == needle) return true;
    }
    return false;
}

btn.addEventListener('click', getWord, false);

function getWord() {
    var word = "";
    var length = random(3,12);
    var last_char = "";
    for (var i=0;i < length; i++) {
        var new_char = "";
        if(inArray(last_char, consonants)) {
            set = randomChoice([consonants,most_common_consonants,vowels,vowels,vowels]);
            new_char = randomChoice(set);
        }
        if (inArray(last_char, vowels)) {
            set = randomChoice([consonants,consonants,most_common_consonants,vowels]);
            new_char = randomChoice(set);
        }
		if (last_char == "e") {
            set = randomChoice([after_e,after_e,after_e,consonants,vowels]);
            new_char = randomChoice(set);
        }
        if (last_char == "") {
            new_char = randomChoice(alphabet);
        }
        word += new_char;
        last_char = new_char;
    }



    word_p.innerHTML = word;
}
