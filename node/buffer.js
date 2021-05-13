const {createServer} = require("http");
const { request } = require("node:http");

createServer((request, response) => {
    response.writeHead(200, {"Content-Type": "text/plain"});
    request.on("data", chunk => response.write(chunk.toString().toUpperCase()));
    request.on("end", () => response.end());
}).listen(8000);

request({
    hostname: "localhost",
    port: 8000,
    method: "POST"
}, response => {
    response.on("data", chunk => process.stdout.write(chunk.toString()));
}).end("Hello server");