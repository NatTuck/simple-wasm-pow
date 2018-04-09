
function bench(op, id) {
  console.log("Start bench: " + id);
  let t0 = performance.now();
  let jj = 0;

  while (performance.now() - t0 < 5000) {
    for (let ii = 0; ii < 50; ++ii) {
      let _foo = op("" + ii);
      jj += 1;
    }
  }

  let ips = jj / 5;

  $(id).text("" + ips);
}

$(function() {
  console.log("Start bench js-sha256");
  bench(sha256, '#js-rate');
});

Module.onRuntimeInitialized = function() {
  bench(Module.sha256, '#wasm-rate');
  console.log("Hello");
};

