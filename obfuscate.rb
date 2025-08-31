def number(x)
    return '(_-_)' if x == 0
    return "(_**#{number(0)})" if x == 1
    x.to_s(2)
        .chars
        .reverse
        .zip(0..)
        .filter{ |x| x[0] == "1" }
        .map{|x| "(_**#{number(x[1])})"}
        .join("+")
        .concat(')')
        .prepend('(')
end

def string(text)
    %q[(''<<] + text.chars.map{|c| number(c.ord)}.join('<<') + ')'
end
def expression(text)
    "->(&__){__['',#{string('eval')},#{string(text)}]}[&:\"\#{#{string('send')}}\"]"
end

def obfuscate(code)
    expression(code).prepend(%q[_="__"=~/$/;])
end

def obfuscate_print(text)
    string(text).prepend(%q[_="__"=~/$/;$><<('' <<]).concat(')')
end

puts obfuscate_print('Hi Vijay anna !')
