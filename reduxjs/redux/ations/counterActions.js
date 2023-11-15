
import { INCREMENT,DECREMENT,RESET } from "./actionTypes.js";

// value=1 default value if user does not pass any value
export const increment = (value=1) => {
    return {
        type:INCREMENT,
        value:value
    }
}

export const decrement = () => {
    return {
        type:DECREMENT
    }
}

export const reset = () => {
    return {
        type:RESET
    }
}