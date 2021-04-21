var a = {}
a.bar = 2

Object.defineProperty(a, "foo",
    { value: "hi" });

console.log(delete a.foo)
console.log(delete a.bar)

a.foo = "world"
console.log(a.foo)


for (var key in a) {
    console.log(key);
}

console.log("foo" in a);
console.log("bar" in a);