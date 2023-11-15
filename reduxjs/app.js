import store from "./redux/store.js";

import { increment, decrement, reset } from "./redux/ations/counterActions.js";

console.log("initial value",store.getState());

store.dispatch(increment());
store.dispatch(increment(100));
store.dispatch(increment(200));
store.dispatch(increment(300));
store.dispatch(decrement())
// store.dispatch(reset());
console.log("after  inc",store.getState());